#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,x;
    cin>>n>>x;
    int cnt=1,sum=0,l;
    rep(i,n){
        cin>>l;
        sum+=l;
        if(sum<=x)cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}