#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define vi vector<int>
#define all(a) a.begin(),a.end()
typedef pair<int,int> P;
const long long mod=1000000007;
const long long inf=1ll<<61;

signed main(){
    int n;cin>>n;
    double bo;
    rep(i,n){
        int a;cin>>a;
        bo+=1.0/(double)a;
    }
    cout<<fixed<<setprecision(13)<<1.0/bo<<endl;
}