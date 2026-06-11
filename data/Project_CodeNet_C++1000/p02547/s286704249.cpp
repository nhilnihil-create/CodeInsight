#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
const int N = 102;
int D[N][3];

int main(){
   int n;
   cin>>n;
   int i;
   for(i=1;i<=n;++i){
      cin>>D[i][1]>>D[i][2];
   }
   for(i=1;i<=n-2;++i){
      if(D[i][1]==D[i][2]&&D[i+1][1]==D[i+1][2]&&D[i+2][1]==D[i+2][2]){
         cout<<"Yes";
         return 0;
      }
   }
   cout<<"No";
}