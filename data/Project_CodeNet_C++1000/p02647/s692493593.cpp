#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    rep(i,n) cin>>a[i];


    while(k--){
        vector<int> imos(n+1,0);
        rep(i,n){
            int l=max(0,i-a[i]);
            int r=min(n,i+a[i]+1);
            //cout<<l<<" "<<r<<endl;;
            imos[l]++;
            imos[r]--;
        }
        for(int i=1;i<n;i++) imos[i]+=imos[i-1];
        //rep(i,n) cout<<a[i]<<" ";
        //cout<<endl;
        imos.pop_back();
        if(a==imos) break;
        a=imos;
        //rep(i,n) cout<<a[i]<<" ";
        //cout<<endl;
    }

    rep(i,n) cout<<a[i]<<" ";
    cout<<endl;
}
