#include <iostream>
#include<vector>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    string S;
    cin>>S;
    int n = S.length();
    vector<int>x(n);
    rep(i,n) {
        int pos = i;
        rep(j,10) {
            if(S[pos]=='R') pos++;
            else if(S[pos]=='L') pos--;
        }
        x[i] = pos;
    }
    vector<int>y(n);
    int tmp;
    rep(j,100) {
        rep(i,n) {
            tmp = x[i];
            x[i] = x[x[x[x[x[x[x[x[x[x[i]]]]]]]]]];
            y[i] = x[i];
            x[i] = tmp;
        }
        rep(i,n) x[i] = y[i];
    }
    
    vector<int>ans(n);
    rep(i,n) {
        ans[y[i]]++;
    }
    rep(i,n) cout<<ans[i]<<" ";

    return 0;
}
