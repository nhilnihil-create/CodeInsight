#include <iostream>
#include <math.h>
using namespace std;



long double dis(long long int x, long long int y){
    long long int sum;
    long long int sq_x, sq_y;
    sq_x = x*x; sq_y = y*y;
    if(sq_x < 0){sq_x = (-1)*sq_x;}
    if(sq_y < 0){sq_y = (-1)*sq_y;}
    

    sum = sq_x + sq_y;
    return sqrt(sum);
}



int main(void){
    
    int N, D;
    long long int x, y;
    long double distance;
    int overD = 0;


    cin >> N; cin >> D;

    for(int i=0; i<N; i++){

        cin >> x;
        cin >> y;

    
        distance = dis(x, y);
    
        if(distance <= D){
            overD++;
        }

    }
    cout << overD;
    

    return 0;
}