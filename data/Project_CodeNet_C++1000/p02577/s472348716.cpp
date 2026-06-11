#include <bits/stdc++.h>
#define ll long long int
#define forr(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
#define oo 100000000000000000
using namespace std;



void _sol(){
    string s; cin >> s;
    ll cnt = 0;
    forr(i,s.size()){
        cnt += s[i] - '0';
    }
    if(cnt%9) cout << "No";
    else cout << "Yes";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    _sol();
}
