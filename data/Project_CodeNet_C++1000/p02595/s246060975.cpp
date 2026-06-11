#include<bits/stdc++.h>
#define rep(i, n) for (int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
 
int main(void){
    int n, d;
    cin>>n>>d;
    vector<pair<int, int> > v(n);
    rep(i, n){
        int x, y;
        cin>>x>>y;
        v[i] = make_pair(x, y);
    }
    int ans = 0;
    rep(i, n){
        if(pow(v[i].first, 2)+pow(v[i].second, 2)<=pow(d, 2)) ans++;
    }
    cout<<ans<<endl;
    return 0;
}