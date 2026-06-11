#include<bits/stdc++.h>
using namespace std;




int main(void){
   int n,m;
   cin>>n>>m;
   vector<int> a(n),b(n);
   for(int i=0;i<m;i++){
      int p;
      string s;
      cin>>p>>s;
      --p;
      if(a[p])continue;
      if(s=="AC"){
         a[p]=1;
      }
      else{
         b[p]++;
      }
   }
   int x=0,y=0;
   for(int i=0;i<n;i++){
      x+=a[i];
      if(a[i])y+=b[i];

   }
cout<<x<<" "<<y<<endl;


return 0;
}


