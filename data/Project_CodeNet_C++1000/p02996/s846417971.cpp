#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;

int main(){
    ll n;
    cin>>n;

    vector<pair<ll,ll>>a(n+1);
    rep2(i,1,n)cin>>a[i].second>>a[i].first;

    sort(a.begin(),a.end());

    rep2(i,1,n){
        a[i].second=a[i].second+a[i-1].second;
        if(a[i].second>a[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
}
