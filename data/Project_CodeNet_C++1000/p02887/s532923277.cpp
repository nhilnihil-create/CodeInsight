#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 1;
    char c = s[0];
    rep(i,n){
        if(s[i] != c){
            c = s[i];
            ans++;
        } 
    }
    cout << ans << endl;
}