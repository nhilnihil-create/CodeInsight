#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << x << "\n";
#define debug2(x,y) cout << x << " " << y << "\n"
#define fi first
#define se second
#define pb push_back
#define ll long long 
const ll mod = 1e9+7;
const int MAX = 2e5+5;

int main() {
    string str;
    cin >> str;
    map<char,int> mp;
    for(char c : str)
        mp[c]++;
    if(mp.size() == 2){
        for(auto i : mp){
            // debug2(i.fi,i.se);
            if(i.second != 2){
                cout << "No" << "\n";
                return 0;
            }
        }
        cout << "Yes" << "\n";
    }else{
        cout << "No" << "\n";
    }
}




