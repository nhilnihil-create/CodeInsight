#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int main(){
  string a;
  cin >> a;
  int n= a.size();
  reverse(a.begin(),a.end());
  vi s(2019);
  s[0]++;
  int sum=0,ten=1;
  ll ans=0;
  rep(i,n){
    sum+=(a[i]-'0')*ten;
    sum%=2019;
    ans+=s[sum];
    s[sum]++;
    ten*=10;
    ten%=2019;
  }
  cout << ans << "\n";
  return 0;
}