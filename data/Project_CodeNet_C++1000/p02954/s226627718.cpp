#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}

int main(){
   string s; cin >> s;
  
   int l=s.length(),rcnt=0,lcnt=0,right,left;
   vector<int> ans(l);
   rep(i,l)ans[i]=0;
   rep(i,l){
      if(s[i]=='R'&&s[i+1]=='L'){
         if(rcnt%2){
            ans[i]=1+rcnt/2;
            ans[i+1]=2+rcnt/2;
         }else{
            ans[i]=1+rcnt/2;
            ans[i+1]=1+rcnt/2;
         }
         left=i; right=i+1; rcnt=0;
         i++;
         continue;
      }
       if(s[i]=='L'&&s[i+1]=='R'){
          lcnt++;
         if(lcnt%2){
            ans[left]+=1+lcnt/2;
            ans[right]+=lcnt/2;
         }else{
            ans[left]+=lcnt/2;
            ans[right]+=lcnt/2;
         }
          lcnt=0;
         continue;
      }
      if(s[i]=='R') rcnt++;
      if(s[i]=='L') lcnt++;
   }
   if(l>0){
      if(lcnt%2){
            ans[left]+=1+lcnt/2;
            ans[right]+=lcnt/2;
         }else{
            ans[left]+=lcnt/2;
            ans[right]+=lcnt/2;
         }
   }
   rep(i,l) cout << ans[i] << " ";
   //cout << "L"<< lcnt<<endl; 
   cout << endl;
   return 0;
}