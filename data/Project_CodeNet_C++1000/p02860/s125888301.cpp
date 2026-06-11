#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

int main(){
  ll N;cin>>N;
  string S;cin>>S;
  int h = N/2;
  string s1 = S.substr(0,h),s2 = S.substr(h,h);
  if(N%2==1) cout<<"No"<<endl;
  else{
    if(s1==s2) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
  }
}