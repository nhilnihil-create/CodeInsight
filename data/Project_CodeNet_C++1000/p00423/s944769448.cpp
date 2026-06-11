#include<iostream>
using namespace std;
int main() {

    int i,j;
    int n,m;
    int round;
    int point_a, point_b;
    int a,b;
    
    while(1) {
        point_a = 0;
        point_b = 0;
        cin >> round;
        if(round == 0) break;
        for(i=0; i<round; i++) {
            cin >> a >> b;
            if( a > b ) {
                point_a += a + b;
            } else if(a < b) {
                point_b += a + b;
            } else {
                point_a += a;
                point_b += b;                
            }
        }
        cout << point_a << " " << point_b << endl;
    }
    

}