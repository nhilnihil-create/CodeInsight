#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  int64_t n;
  cin >> s >> n;
  int64_t k=s.size(),cnt=0;  
  if(s==string(k,s[0]))cout << n*k/2 << endl;
  else{
      for(int64_t i=0;i<k;i++){
        if(s[i]==s[i+1] && s[i+1]==s[i+2]){
           cnt++;
           i++;
        }else if(s[i]==s[i+1])cnt++;
      }
    if(s[0]==s[k-1]){
      int a=0,b=0;
      for(int i=0;i<k;i++){
        if(s[i]==s[0])a++;
        else break;
      }
      for(int i=k-1;i>=0;i--){
        if(s[i]==s[k-1])b++;
        else break;
      }
      cout << (int64_t)cnt*n-(int64_t)((a/2)+(b/2)-((a+b)/2))*(n-1) << endl;
    }else cout << (int64_t)cnt*n << endl;
  }
}