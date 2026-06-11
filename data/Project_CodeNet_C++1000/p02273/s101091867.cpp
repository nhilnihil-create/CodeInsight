#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
 
#define DtR(degrees) ((degrees)*(M_PI/180.0f))
 
void moveXY( double& x, double& y, double mx, double my, double si, double co )
{
    double xy[3][1] = { {x},
                        {y},
                        {1}, };
    double r[3][3] = { { co, -si, 0 },
                    { si, co, 0 },
                    { 0, 0, 1 } };
    double m[3][3] = { { 1, 0, mx },
                    { 0, 1, my },
                    { 0, 0, 1 } };    
    int i,j,k;
    double a[3][3] = { {0} };
    for( i=0; i<3; i++ ) {
        for( j=0; j<3; j++ ) {
            for( k=0; k<3; k++ ) {
                a[i][j] += m[i][k]*r[k][j];
            }
        }
    }
 
    double b[3][1] = { {0} };          
    for( i=0; i<3; i++ ) {
        for( j=0; j<3; j++ ) {
            b[i][0] += a[i][j]*xy[j][0];
        }
    }
 
    x = b[0][0];
    y = b[1][0];
    return;
}
 
void kochCurve( int n, double px, double py, double px2, double py2 )
{
 
    double sx, sy;
    double ux, uy;
    double tx, ty;
    double d = sqrt( pow( px2-px, 2 ) + pow( py2-py, 2 ) );
     
    sx = d/3;
    ux = d/2;
    tx = sx*2;
    sy = ty = 0;
    uy = sin( DtR(60) )*sx;
     
    double si=0;
    double co=0;
	py = py*100000;
	py = (double)(int)py;
	py = py/100000;
	py2 = py2*100000;
	py2 = (double)(int)py2;
	py2 = py2/100000;
    if( px < px2 ) {
        if( py == py2 ) {
            si = sin( DtR(0) );
            co = cos( DtR(0) );            
        } else if( py < py2 ) {
            si = sin( DtR(60) );
            co = cos( DtR(60) );            
        } else if( py2 < py ) {
            si = sin( DtR(-60) );
            co = cos( DtR(-60) );
        }
    } else if( px2 < px ) {
        if( py == py2 ) {
            si = sin( DtR(-180) );
            co = cos( DtR(-180) );                 
        } else if( py2 < py ) {
            si = sin( DtR(-120) );
            co = cos( DtR(-120) );
        } else if( py < py2 ) {
            si = sin( DtR(-240) );
            co = cos( DtR(-240) );            
        }
    }
 
	moveXY( sx, sy, px, py, si, co );
	if( 1 < n ) {
		kochCurve( n-1, px, py, sx, sy );
	}
	cout<<sx<<" "<<sy<<endl; 
	
	moveXY( ux, uy, px, py, si, co );
	if( 1 < n ) {
		kochCurve( n-1, sx, sy, ux, uy );
	}
	cout<<ux<<" "<<uy<<endl;
	
	moveXY( tx, ty, px, py, si, co );
	if( 1 < n ) {
		kochCurve( n-1, ux, uy, tx, ty );
	}
	cout<<tx<<" "<<ty<<endl;
	
	if( 1 < n ) {
		kochCurve( n-1, tx, ty, px2, py2 );
	}
 
    return;
}
 
int main()
{
	cout.setf( ios::fixed );	
	int n;
	cin>>n;
	
	cout<<0.0<<" "<<0.0<<endl;	
	if( 1 <= n ) {
		kochCurve( n, 0, 0, 100.0, 0.0 );
	}
	cout<<100.0<<" "<<0.0<<endl;	
 
    return 0;
}