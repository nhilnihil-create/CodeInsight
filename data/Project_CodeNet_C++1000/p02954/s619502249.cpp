#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 //実装面倒→ランレングス圧縮
int main() {
   string s;
   cin>>s;
   vector<int> ans(s.length());
   int firstR=0;//島のはじめのRのインデックス
   int firstL;//島のはじめのLのインデックス
   rep(i,s.length()-1){
       if(s[i+1]=='L'&&s[i]=='R')firstL=i+1;
       if(s[i+1]=='R'&&s[i]=='L'){
           int sima=i+1-firstR;
           if(sima%2==0){
               ans[firstL-1]=sima/2;
               ans[firstL]=sima/2;
           }
           else if(firstR%2==(firstL-1)%2){
               ans[firstL-1]=sima/2+1;
               ans[firstL]=sima/2;
           }
           else{
               ans[firstL-1]=sima/2;
               ans[firstL]=sima/2+1;
           }
           firstR=i+1;
       }
   }

   //最後だけ例外処理
   int sima=s.length()-firstR;
   if(sima%2==0){
               ans[firstL-1]=sima/2;
               ans[firstL]=sima/2;
           }
           else if(firstR%2==(firstL-1)%2){
               ans[firstL-1]=sima/2+1;
               ans[firstL]=sima/2;
           }
           else{
               ans[firstL-1]=sima/2;
               ans[firstL]=sima/2+1;
           }




   rep(i,s.length()) cout<<ans[i]<<" ";
}

//サンプルは通ったが...