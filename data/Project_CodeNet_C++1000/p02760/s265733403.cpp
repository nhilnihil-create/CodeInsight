#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    
    int table[9];
    vector<bool> t(10,false);

    rep(i,9) cin >> table[i];
    map<int,int> mp;
    rep(i,9){
            mp[table[i]] = i+1;
    }

    int k;
    cin >> k;
    int tmp;
    rep(i,k){
        cin >> tmp;
        if(mp[tmp] != 0){
            t[mp[tmp]] = true;
        } 
    }

    if(t[1] == true && t[2] == true && t[3] == true ){
        cout<< "Yes" << endl;
        return 0;
    }
    if(t[4] == true && t[5] == true && t[6] == true ){
        cout<< "Yes" << endl;
        return 0;
    }
    if(t[7] == true && t[8] == true && t[9] == true ){
        cout<< "Yes" << endl;
        return 0;
    }
    if(t[1] == true && t[4] == true && t[7] == true ){
        cout<< "Yes" << endl;
        return 0;
    }
    if(t[2] == true && t[5] == true && t[8] == true ){
        cout<< "Yes" << endl;
        return 0;
    }
    if(t[3] == true && t[6] == true && t[9] == true ){
        cout<< "Yes" << endl;
        return 0;
    }
    if(t[1] == true && t[5] == true && t[9] == true ){
        cout<< "Yes" << endl;
        return 0;
    }
    if(t[3] == true && t[5] == true && t[7] == true ){
        cout<< "Yes" << endl;
        return 0;
    }
    
    cout << "No" << endl;
    return 0;
}
