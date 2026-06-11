#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
   int N;
   cin>>N;
   int odd=N/2;
   if(N%2==1){
       odd++;
   }
   
   double ans=(double)odd/N;
   cout<<fixed<<setprecision(6);
   cout<<ans<<endl;
}
