#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    int a, b;
    cin >> a >> b ;
    //*/

    /*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;

    sort(vec.begin(), vec.end());
    //*/
    
    //Sunny, Cloudy, Rainy
    /*
    if( a < 10 && b < 10 ){
        cout << a * b << endl;
    } else {
        cout << -1 << endl;
    }
    //*/
    
    cout << b + 100 * ( 10 - min(a, 10) ) << endl;
    
    //printf("%lf\n", ((a / 2 + a % 2) / a));

    return 0; 
}
