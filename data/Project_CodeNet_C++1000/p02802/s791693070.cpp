#include <iostream>
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int main()
{
   int n,m;
   cin>>n>>m;
   vector<int> v(n),p(n);
   string s;
   int a;
   int k=0;
   int sum1=0;
   rep(i,m) 
   {  cin>>a;
      cin>>s;
      a--;
      if(v[a]) continue;
       if(s=="AC"){
         v[a]=1;
        }
       else {
           p[a]++;
       }
   }
   rep(i,n){
       k=k+v[i];
       if(v[i]) sum1=sum1+p[i];
   }
   cout<<k<<" "<<sum1<<endl;
   return 0;
}