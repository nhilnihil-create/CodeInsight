#include <bits/stdc++.h>

using namespace std;

int main()
{
   int a,b,c,k,sum=0;
   cin>>a>>b>>c>>k;
   while(k&&a){
    sum++;
    a--;
    k--;
   }
   while(k&&b){
    b--;
    k--;
   }
   while(k&&c){
    sum--;
    c--;
    k--;
   }
   cout<<sum<<endl;
}
