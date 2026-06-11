#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
   string s;cin >>s;
   int k;cin >>k;
   ll ans=0;
   ll a=0;
   ll b=0;
   bool flg=true;
   char key=s[0];
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]==key)a++;
        else break;
    }
    reverse(all(s));
    key=s[0];
    for (int i = 0; i < s.size(); ++i) {
        if(s[i]==key)b++;
        else break;
    }
    reverse(all(s));
//    cout <<s<<endl;
    for (int i = 1; i < (int) s.size(); ++i) {
        if(s[i]==s[i-1]){
            ans+=k;
            i++;
        }
    }
//    cout <<ans<<endl;
    ll sub=0;
    if(s[0]==s.back()) {
        sub += a / 2 + b / 2 - (a + b) / 2;
    }
   ans-=sub*(k-1);
   if(a==s.size()){
       cout <<(a*k)/2<<endl;
   }
   else {
       cout << ans << endl;
   }
}
