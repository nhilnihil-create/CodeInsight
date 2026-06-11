#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,l;
    cin>>n>>l;
    int ans=0,min_a=l;
    bool flag;
    rep(i,n){
        ans=ans+l+i;
        if(abs(min_a)>abs(l+i)){
            min_a=l+i;
        }
    }
    cout<<ans-min_a<<endl;

    return 0;
}