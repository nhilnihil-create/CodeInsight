#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main()
{
    int n;
    cin >> n;
    vector<P> v(n);
    rep(i,n){
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(b,a);
    }
    
    sort(ALL(v));
    int t = 0;
    string ans = "Yes";
    rep(i,n){
        t+=v[i].second;
        if(t > v[i].first){
            ans = "No";
            break;
        }
    }   

    cout << ans << endl;

    return 0;
}