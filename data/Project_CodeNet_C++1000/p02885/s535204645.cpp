#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    int a, b ;
    cin >> a >> b ;
    //*/

    /*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;

    sort(vec.begin(), vec.end());
    //*/
    
    /*
    if( a < 10 && b < 10 ){
        cout << a * b << endl;
    } else {
        cout << -1 << endl;
    }
    //*/
    
    cout << max(a - 2 * b, 0) << endl;

    return 0; 
}
