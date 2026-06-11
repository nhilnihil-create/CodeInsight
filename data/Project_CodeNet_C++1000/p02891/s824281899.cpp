#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string s;
    ll k,ans=0,tmp=0;
    cin>>s>>k;
    ll n = s.size();
    ll a=1;
    for(int i=0; i<n; i++) {
        if(s[i]==s[i+1]) a++;
        else {
          	if(a == 1) a--;
            ans += a/2;
          	tmp++;
          	a=1;
        }
    }
    if(tmp == 1) cout<<n * k / 2<<endl;
    else if(s.front() == s.back()) {
      	ll fr = 0, ba = 0;
        for(int i=0; i<n; i++) {
            fr++;
            if(s[i] != s[i+1]) break;
        }
        for(int i=n-1; i>=0; i--) {
            ba++;
            if(s[i] != s[i-1]) break;
        }
        cout<<ans * k - (k-1) * ((fr/2) + (ba/2) - (fr+ba)/2)<<"\n";
    }
  	else cout<<ans * k<<endl;
}