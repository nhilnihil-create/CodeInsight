#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int n, k;
    cin >> n >> k;
    int mx = (n-1)*(n-2)/2;
    if(k>mx){
        cout <<-1<<endl;return 0;
    }
    vector<P> hen;
    rep(i,n-1) hen.push_back(P(1,i+2));
    int x=2,y=3;
    rep(i,mx-k){
        hen.push_back(P(x,y));
        if(y<n){
            y++; continue;
        }else{
            x++;
            y=x+1;
            continue;
        }
    }
    cout << hen.size() <<endl;
    for(auto i:hen){
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}