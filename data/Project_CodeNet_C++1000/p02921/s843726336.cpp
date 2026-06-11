#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    //*
    string a, b;
    cin >> a >> b ;
    //*/
    int cnt = 0;

    for(int i = 0; i < min(a.size(), b.size()); i++){
        if(a.at(i) == b.at(i)){
            cnt++;
        }
    }

    /*
    vector<int> vec(3);
    cin >> vec.at(0) >> vec.at(1) >> vec.at(2) ;
    
    sort(vec.begin(), vec.end());
    //*/
    
    /*
    if( a < b ){
        cout << 0 << endl;
    } else {
        cout << 10 << endl;
    }
    //*/
    
    cout << cnt << endl;

    return 0; 
}
