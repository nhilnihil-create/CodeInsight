#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) (a).begin(),(a).end()
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,k,c;cin>>n>>k>>c;
  string s;cin>>s;
  lvector A,B;
  ll apos=0,bpos=n-1;
  while(A.size()<k&&apos<n) {
    if(s[apos]=='x') {apos++;continue;}
    if(A.size()==0||A.back()+c<apos) A.emplace_back(apos);
    apos++;
  }
  while(B.size()<k&&bpos>-1) {
    if(s[bpos]=='x') {bpos--;continue;}
    if(B.size()==0||B.back()-c>bpos) B.emplace_back(bpos);
    bpos--;
  }
  reverse(ALL(B));
  rep(i,k) if(A[i]==B[i]) print(A[i]+1);
  return 0;
}