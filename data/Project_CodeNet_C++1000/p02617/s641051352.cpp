#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits.h>
#include <cmath>
#include <map>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
using P = pair<int,int>;
using ll = long long;
int main(){
    int n;
    cin>>n;
    vector<int> u(n-1),v(n-1);
    rep(i,n-1){
        cin>>u[i]>>v[i];
        if(u[i]>v[i])swap(u[i],v[i]);
        u[i]--;
        v[i]--;
    }
    vector<ll> cnt(n+1,0);
    rep(i,n-1){
        cnt[0]+=n-v[i];
        cnt[u[i]+1]-=n-v[i];
    }
    for(int i=1;i<n;i++){
        cnt[i]=cnt[i-1]+cnt[i];
    }
    for(int i=1;i<n;i++){
        cnt[i]=cnt[i-1]+cnt[i];
    }
    ll all=0;
    for(int i=1;i<=n;i++){
        all+=(ll)(n-i+1)*i;
    }
    cout<<all-cnt[n-1]<<endl;
}

