#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

int main(){
    
    int n;
    cin>>n;
    vector<ll> A(n), B(n);
    vector<P> pr(n);
    ll sum=0;
    rep(i,n){
        cin>>A[i]>>B[i];
        pr[i] = make_pair(B[i], A[i]);
    }
    sort(pr.begin(), pr.end());
    rep(i,n){
        sum+=pr[i].second;
        if(sum>pr[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    return 0;
    
}
