#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    string s;
    cin >> n >> k >> s;
    int sc=0;
    for(int i = 0; i < n-1; i++) {
        if(s[i]==s[i+1]) sc++;
    }
    int ans=min(sc+2*k,n-1);
    cout << ans << "\n";
    return 0;
}