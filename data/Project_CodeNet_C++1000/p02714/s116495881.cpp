#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
#define INF 1000000007
#define llINF 1000000000000000007
// cin.eof() 入力個数の問題

int main() {
int n;
cin >> n;
string s;
cin>>s;
map<char,ll>m;
rep(i,n){
m[s[i]]++;
} 
ll ans=m['R']*m['G']*m['B'];
ll count=0;
rep(i,n){
  rep(j,n){
  int k=2*j-i;
  if(k<0||k>=n) continue;
  if(s[j]!=s[i]&&s[i]!=s[k]&&s[k]!=s[j]) count++;
    }
}
cout<<ans-count/2<<endl;
  return 0;
}
