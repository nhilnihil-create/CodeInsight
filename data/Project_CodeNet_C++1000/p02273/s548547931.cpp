#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>

using namespace std;

#define pi 3.141592653589793

queue< pair< double , double > > points;

void make_coordination( int n, queue< pair< double , double > > points, double length ){

    double left[2], right[2], x, y, i = 0;

    left[0] = 0.0;
    left[1] = 0.0 ;

    for( i = 0 ; i < n ;  i++ ){

    while(1){

        left[0] = points.front().first;
        left[1] = points.front().second;

        points.pop();

        right[0] = points.front().first;
        right[1] = points.front().second;

 

        points.push( make_pair( left[0], left[1] ) );

        x =  ( right[0] - left[0] ) / 3.0 + left[0] ;
        y =  ( right[1] - left[1] ) / 3.0  + left[1] ;

        points.push( make_pair( x , y ) );

        x = left[0] + ( ( right[0] - left[0] ) / 3.0 ) * cos( pi / 3 ) - ( ( right[1] - left[1] ) / 3.0 ) * sin( pi / 3 ) + ( right[0] - left[0] ) / 3.0;
        y = left[1] + ( ( right[0] - left[0] ) / 3.0 ) * sin( pi / 3 ) + ( ( right[1] - left[1] ) / 3.0 ) * cos( pi / 3 ) + ( right[1] - left[1] ) / 3.0 ;



        points.push( make_pair( x , y ) );    

        x =  2 * ( right[0] - left[0] ) / 3.0 + left[0] ;
        y =  2 * ( right[1] - left[1] ) / 3.0  + left[1] ;

        points.push( make_pair( x , y ) );



        if( right[0] > 99.99999999  ) { 
            
            points.push( make_pair( right[0], right[1] ) );
            points.pop();
            break;
        
        }

    }

    }

    int j = points.size(); 

    for( i = 0; i < j; i++){

        printf("%f %f\n", points.front().first, points.front().second);
        points.pop();

    }

}


int Koch_curve(int n){

    int i = 0;
    double x, y, length, left, right;

    x = 0.0;
    y = 0.0;

    points.push( make_pair( x, y) );

    x = 100.0;
    y = 0.0;

    points.push( make_pair( x, y) );

    length = 100.0;

        make_coordination( n,  points, length);

    return 0;

}





int main(){

    int n;

    scanf("%d", &n);

    Koch_curve(n);
   
    return 0;

}