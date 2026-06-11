#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)

const int M=1000005;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> cnt(M,0);
    for(int x:a){
        if(cnt[x]!=0){
            cnt[x]=2;
            continue;
        }
        for(int j=x;j<M;j+=x) cnt[j]++;
    }
    int ans=0;
    for(int x:a){
        if(cnt[x]==1) ans++;
    }
    cout << ans << endl;
}