#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        v[i]={b,a};
    }

    sort(all(v));
    int pre=0;
    rep(i,n){
        if(pre>v[i].first){
            cout<<"No"<<endl;
            return 0;
        }
        pre+=v[i].second;
        if(pre>v[i].first){
            cout<<"No"<<endl;
            return 0;
        }
    }

    cout<<"Yes"<<endl;
}
