#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string s[5];
    for(int i = 0; i < 2; i++) cin >> s[i];
    map<string, int> mp;
    for(int i = 0; i < 2; i++){
        int x;
        cin >> x;
        mp[s[i]] = x;
    }
    string x;
    cin >> x;
    mp[x]--;
    for(int i = 0; i < 2; i++) cout << mp[s[i]] << ' ';


    return 0;
}


