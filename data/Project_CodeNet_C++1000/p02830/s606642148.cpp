#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;
    string s,t;

    cin >> n >> s >> t;

    string ans("");
    rep(i,2*n){
        if(i%2==0){
            ans += s[i/2];
        }else{
            ans += t[i/2];
        }
    }

    cout << ans << endl;

    return 0;
}