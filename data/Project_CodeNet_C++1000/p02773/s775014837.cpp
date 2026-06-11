#include <bits/stdc++.h>
#include <iostream>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    int n;
    string s;
    map<string, int> mp;
    cin >> n;
    while (n){
        cin >> s;
        mp[s] ++;
        n --;
    }
    
    int mx = 0;
    for (auto p: mp){
        mx = max(mx, p.second);
    }

    for (auto p: mp){
        if (p.second != mx) continue;
        cout << p.first << endl;
    }

    return 0;
}