#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep2(i,n) for(int i=1;i<(n);i++)
typedef long long ll;

int main(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> r(0),g(0),b(0);
    rep(i,n){
        if(s[i]=='R') r.push_back(i);
        if(s[i]=='G') g.push_back(i);
        if(s[i]=='B') b.push_back(i);
    }
    ll ans=r.size()*g.size()*b.size();
    for(auto i:r){
        for(auto j:g){
            if(i%2==j%2){
                if(s[(i+j)/2]=='B') ans--;
            }
            if(0<=2*i-j && 2*i-j<n){
                if(s[2*i-j]=='B') ans--;
            }            
            if(0<=2*j-i && 2*j-i<n){
                if(s[2*j-i]=='B') ans--;
            }            
            
        }
    }
    cout << ans << endl;

}