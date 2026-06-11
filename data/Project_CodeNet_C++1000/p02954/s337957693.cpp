#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef std::pair<int,int> pair2;
typedef std::pair<int,pair2> pair3;
const ll INF = 1LL<<60;

int main(){
  string S;
  cin>>S;

  char now='R';//今の文字
  ll changeRL=0;//RLになった時のLの時の番号 
  ll counter[2]={0,0};//0奇数，1偶数　の数
  vector<ll> ans((ll)S.length(),0);
  //cout<<(ll)S.length()<<endl;
for(ll i=0;i<(ll)S.length();i++){
 if(now=='R'&&S[i]=='R'){
   counter[i%2]++;
        now='R';
 }
   if(now=='L'&&S[i]=='L'){
   counter[i%2]++;
          now='L';
 }
   if(now=='R'&&S[i]=='L'){
   changeRL=i;
   counter[i%2]++;
          now='L';
 }
   if(now=='L'&&S[i]=='R'){
     ans[changeRL]=counter[changeRL%2];
     ans[changeRL-1]=counter[(changeRL+1)%2];   
     counter[0]=0;
     counter[1]=0;
     counter[i%2]++;
     now='R';
   }
}
       ans[changeRL]=counter[changeRL%2];
     ans[changeRL-1]=counter[(changeRL+1)%2];   

  for(ll i=0;i<(ll)S.length();i++){
  cout<<ans[i]<<" ";
  }
  
  
  
}
