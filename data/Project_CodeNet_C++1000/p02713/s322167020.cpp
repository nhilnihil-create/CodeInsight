#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
    int K;
    cin>>K;
    int ans=0;
    rrep(i,K){
        rrep(j,K){
            rrep(l,K){
                int a=__gcd(i,j);
                ans+=__gcd(a,l);
            }
        }
    }
  cout<<ans<<endl;
}