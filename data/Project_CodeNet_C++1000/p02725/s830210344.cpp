#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using Graph = vector<vector<int>>;
using ll = long long;


int main() {
    int k,n;
    cin>>k>>n;
    vector<int> a(n);
    rep(i,n){
        cin>>a[i];
    }
    int maxd=0;
    rep(i,n-1){
        maxd=max(a[i+1]-a[i],maxd);
    }
    maxd=max(a[0]+k-a[n-1],maxd);
    cout<<k-maxd<<endl;
}