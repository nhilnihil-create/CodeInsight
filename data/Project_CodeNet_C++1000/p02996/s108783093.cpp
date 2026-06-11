#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;
typedef pair<int, int> P;

int main(){
    int n;
    cin>>n;
    vector<P> dat(n);
    rep(i,n) cin>>dat[i].second>>dat[i].first;
    sort(dat.begin(),dat.end());
    int now=0;
    rep(i,n){
        now+=dat[i].second;
        if(now>dat[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}