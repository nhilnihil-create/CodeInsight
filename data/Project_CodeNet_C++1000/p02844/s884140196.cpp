#include<bits/stdc++.h>
using namespace std;

int main(void){
   int N;
   cin>>N;
   string S;
   cin>>S;
   long long ans=0;
   for(int i=0;i<1000;i++){
      int count=0;
      int num[3]={i/100,(i/10)%10,i%10};
      for(int i=0;i<N;i++){
         if(num[count]==S[i]-'0') count++;
      }
      if(count==3) ans++;
   }
   cout<<ans<<endl;
   return 0;
}
