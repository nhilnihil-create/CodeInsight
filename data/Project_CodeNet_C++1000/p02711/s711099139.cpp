#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

   int cnt=0;
   while(n>0){
    int x=n%10;
    if(x ==7)cnt++;
    n/=10;
   }
   if(cnt>0)cout<<"Yes\n" ;
   else
    cout<<"No\n" ;




return 0;

}
