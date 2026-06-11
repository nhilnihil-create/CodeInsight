#include <iostream>
#include<vector>
#include<utility>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;



int main() {
    int n,l;
    cin>>n>>l;
    vector<pair<int,int>>t(n);
    rep(i,n) t[i]=pair<int,int>(-abs(l+i),l+i);
    sort(rng(t));
    t.pop_back();
    int ans=0;
    rep(i,n-1) ans += t[i].second;
    cout<<ans<<endl;

    return 0;
}