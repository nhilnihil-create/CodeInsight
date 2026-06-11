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
    
    //*
    if( abs(a - b) % 2 != 0 ){
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << abs(a - b) / 2 + min(a, b) << endl;
    }
    //*/
    
    //cout << max(c - a + b, 0) << endl;

    return 0; 
}
