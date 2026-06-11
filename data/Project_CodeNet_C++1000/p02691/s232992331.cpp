#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
const ll MOD=998244353;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;

int main(){
    int n;cin>>n;
    vector<ll> A(n),B(n),C(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
        B[i]=i+1+A[i];
        C[i]=i+1-A[i];
    }
    sort(C.begin(),C.end());
    C.push_back(INF);
    ll ans=0;
    for(int i=0;i<n;i++){
        ans+=(ll)(upper_bound(C.begin(),C.end(),B[i])-lower_bound(C.begin(),C.end(),B[i]));
    }
    cout<<ans<<endl;
    return 0;
}