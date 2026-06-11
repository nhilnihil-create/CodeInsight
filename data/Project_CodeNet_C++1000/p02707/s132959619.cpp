#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;

int main(){
    int n; cin>>n;
    vector<int> ans(n);
    rep(i,n-1){
        int now; cin>>now; now--;
        ans[now]++;
    }
    rep(i,n) cout<<ans[i]<<endl;
}
