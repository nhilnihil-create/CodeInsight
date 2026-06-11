#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int main(){
    string s,t;
    cin >> s >> t;
    int ans=0;
    rep(i,s.size()){
        if(s.at(i)!=t.at(i)){
            ans++;
        }
    }
    cout << ans << endl;
}
