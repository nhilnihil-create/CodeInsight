#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
  int n,ans=0;
  string s;
  cin>>n>>s;
  for(int a=0;a<s.size();a++){
    int Z[s.size()-a];
    Z[0]=s.size()-a;
    int i=1,j=0;
    while(i+a<s.size()){
      while(i+j+a<s.size() && s[a+j]==s[a+i+j])j++;
      Z[i]=j;
      ans=max(ans,min(i,Z[i]));
      if(j==0){
        i++;
        continue;
      }
      int k=1;
      while(k<j && k+Z[k]<j){
        Z[i+k]=Z[k];
        ans=max(ans,min(i+k,Z[i+k]));
        k++;
      }
      i += k;
      j -= k;
    }
  }
  cout<<ans<<endl;
}
