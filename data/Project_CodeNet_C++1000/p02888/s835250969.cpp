#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n,ans=0;
    cin >> n;
    vector<int> l(n);
    rep(i,n) cin >> l[i];
    sort(l.begin(),l.end());
    for(int i=0;i<n-2;++i){
        bool ok=false;
        for(int j=i+1;j<n-1;++j){
            for(int k=j+1;k<n;++k){
                if(l[k]<l[i]+l[j]){
                    ++ans;
                }else{
                    ok=true;
                }
                if(ok){
                    ok=false;
                    break;
                }
            }
        }
    }
    cout << ans << "\n";
    return 0;
}   