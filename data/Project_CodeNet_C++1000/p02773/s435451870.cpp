#include <bits/stdc++.h>
using namespace std;

int main() {
    map<string,int>map;
    int len;
    cin >> len;
    int mx = 0;
    while(len--){
        string s;
        cin >> s;
        map[s]++;
        mx = max(map[s],mx);
    }
    for(auto x : map){
        if(x.second == mx){
            cout << x.first << endl;
        }
    }
}