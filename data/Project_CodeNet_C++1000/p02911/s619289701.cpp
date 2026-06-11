#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    int n,k,q; cin>>n>>k>>q;
    ll a[n];
    rep(i,n)a[i]=0;

    int tmp;
    rep(i,q){
        cin>>tmp;
        --tmp;
        ++a[tmp];
    }
    
    rep(i,n){
        if(q - a[i] <k)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

	return 0;
}