#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
#define repp(i,n,s) for (int i= (int)(n); i >= (int)(s); i--)
#define mp make_pair
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    string s;cin>>s;
    s += "R";
    int n = s.size();
    vector<int> li(n),ans(n);
    int j = 1,f = 1,t = 0;
    char x = s[0];
    rep(i,1,n){
        if (x!=s[i]){
            if (f==1){
                rep(k,i-j,i){
                    li[k] = (i-k)*f;
                }
            }else{
                rep(k,i-j,i){
                    li[k] = (k-t)*f;
                }
            }
            t = i-1;
            f*=(-1);
            x = s[i];
            j = 1;
        }else{
            j++;
        }
    }
    rep(i,0,n-1){
        if (li[i]%2==0){
            ans[i+li[i]]++;
        }else{
            if (li[i]>0){
                ans[i+li[i]-1]++;
            }else{
                ans[i+li[i]+1]++;
            }
        }
    }
    rep(i,0,n-1){
        cout<<ans[i]<<endl;
    }
}