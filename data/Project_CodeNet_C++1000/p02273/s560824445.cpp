#include<iostream>
#include<cmath>
using namespace std;

struct point{
	double x, y;
};

void kochkoch( point p1, point p2, int depth ){

	if( !depth ){
		return;
	}else{

		point tp1, tp2, tp3;
		tp1.x=( p2.x+2.0*p1.x )/3.0;
		tp1.y=( p2.y+2.0*p1.y )/3.0;
		tp3.x=( p1.x+2.0*p2.x )/3.0;
		tp3.y=( p1.y+2.0*p2.y )/3.0;
		tp2.x=( tp3.x-tp1.x )*cos(M_PI/3.0) - ( tp3.y-tp1.y )*sin(M_PI/3.0) + tp1.x;
		tp2.y=( tp3.x-tp1.x )*sin(M_PI/3.0) + ( tp3.y-tp1.y )*cos(M_PI/3.0) + tp1.y;

		kochkoch( p1, tp1, depth-1 );
		cout<<tp1.x<<' '<<tp1.y<<endl;
		
		kochkoch( tp1, tp2, depth-1 );
		cout<<tp2.x<<' '<<tp2.y<<endl;

		kochkoch( tp2, tp3, depth-1 );
		cout<<tp3.x<<' '<<tp3.y<<endl;

		kochkoch( tp3, p2, depth-1 );
	}
}

int main()
{
	point p1, p2;

	p1.x=0.0;
	p1.y=0.0;
	p2.x=100.0;
	p2.y=0.0;

	int depth;
	cin>>depth;

	cout<<p1.x<<' '<<p1.y<<endl;
	kochkoch( p1, p2, depth );
	cout<<p2.x<<' '<<p2.y<<endl;
}
		