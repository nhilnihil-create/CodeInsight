#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
ll mod = 1000000007;

int main(){
    string s;cin>>s;
    string x = to_string(s[0]);
    vector<string> a;
    int ans = 1;
    int cnt = 1;
    while (cnt<s.size()){
       if (x==to_string(s[cnt])){
           if (cnt+2<s.size()) {
               x = to_string(s[cnt+2]);
               ans+=2;
           }else if(cnt+2==s.size()) ans++;
           cnt+=3;
       }else{
           x = to_string(s[cnt]);
           cnt++;
           ans++;
       }
    }
    cout<<ans<<endl;
}