#include <iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
typedef long long ll;

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<int>d(n);
    rep(i,n)cin>>d[i];
    sort(rng(d));
    int ans;
    ans = d[n/2]-d[n/2-1];
    cout<<ans<<endl;

    return 0;
}