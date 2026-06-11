#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    int cnt = 0;
    int a, b, c;
    cin >> c >> a >> b ;
    //*/

    /*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;

    sort(vec.begin(), vec.end());
    //*/
    
    for(int i = a ; i <= b; i++){
        if(i % c == 0){
            cnt++;
        }
    }
    
    //*
    if( cnt != 0 ){
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }
    //*/
    
    //cout << ((floor(a / 2) + fmod(a, 2)) / a) << endl;
    
    return 0; 
}
