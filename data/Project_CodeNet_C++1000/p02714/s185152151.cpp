#include<bits/stdc++.h>
#define ll long long
#define st string
#define f(i,l,r) for(ll i=l;i<=r;i++)
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n,ans = 0;
    ll dem1 = 0,dem2 = 0,dem3 = 0;
    st s;
    cin >> n >> s;
    f(i,0,s.size()-1){
       if(s[i] == 'R') dem1 ++;
       else if(s[i] == 'G') dem2 ++;
       else dem3 ++;
    }
    ans = dem1 * dem2 * dem3;
    f(i,0,s.size()-1){
       f(j,0,i-1){
          if(s[i] != s[j]){
              ll pos = 2 * i - j;
              if(pos < s.size() && s[pos] != s[i] && s[pos] != s[j]) ans --;
          }
       }
    }
    cout << ans;
    return 0;
}
