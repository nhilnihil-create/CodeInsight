#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>
#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;


int main(){
    string s;
    cin >> s;
    map<int,int> mp;

    rep(i,4){
        mp[s[i]-'A']++;
    }

    for(auto e : mp) {
        if(e.second != 2){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}