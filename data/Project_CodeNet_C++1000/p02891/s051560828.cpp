#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;
const int mod= 1e+9+7;

int main(){
  string s; cin>>s;
  ll K; cin>>K;
  if(s.size()==1){
    cout<<K/2<<endl;
    return 0;
  }
  vector<ll>a(110);
  char c;
  ll cnt;
  ll j=0;
  rep(i,s.size()){
    c=s[i];
    cnt=1;
    while(s[i+1]==c){
      cnt++;
      i++;
      if(i>=s.size()-1)break;
    }
    if(cnt>=2){
      a[j]=cnt;
      j++;
    }
  }
  ll sum=0;
  rep(i,j){
    sum+=a[i]/2;
}

ll b,d;
if(s[0]!=s[s.size()-1]){
  cout<<sum*K<<endl;
}
else{
  c=s[0];
    cnt=1;
    ll i=0;
    while(s[i+1]==c){
      cnt++;
      i++;
      if(i==s.size()-1)break;
    }
   b=cnt;

   i=s.size()-1;
    cnt=1;
    while(s[i-1]==c){
      cnt++;
      i--;
      if(i==0)break;
    }
   d=cnt;
   if(b+d>=s.size())cout<<(s.size()*K)/2<<endl;
   else cout<<sum*K-(K-1)*((b/2)+(d/2)-((b+d)/2))<<endl;
}

}

