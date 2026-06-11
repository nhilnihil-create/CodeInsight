#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long a,b,t=0;
    cin>>a>>b;
    long long c[b];
    for(int i=0;i<b;i++)
     cin>>c[i];
     
    sort(c,c+b,greater<int>());
     
     for(int i=0;i<b;i++){
         a=a-c[i];
         if(a<=0)
         { cout<<"Yes";
          t++;
          break;}
     }
     if(t==0)
      cout<<"No";
    return 0;
}
     
   


