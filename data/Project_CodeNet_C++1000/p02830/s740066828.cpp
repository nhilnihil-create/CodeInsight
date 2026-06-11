#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;



int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    string s, t;
    cin >> n >> s >> t;
    for(int i = 0; i < n; i++) cout << s[i] << t[i];

    return 0;
}