#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
  int N;
  string S;
  cin>>N>>S;
  int ans=0;
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      for(int k=0;k<10;k++){
        int a=0;
        for(char &c:S){
          if(c=='0'+i && a==0)
            a=1;
          else if(c=='0'+j && a==1)
            a=2;
          else if(c=='0'+k && a==2){
            a=3;
            break;
          }
        }
        if(a==3)
          ans++;
      }
  cout<<ans<<endl;
}