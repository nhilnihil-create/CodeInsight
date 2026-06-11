#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;
typedef long long ll;



  int main(){

   int n,k,Q;
   cin>>n>>k>>Q;
   int a[n];

   for(int i=1;i<=n;i++)
     a[i] = k;

 long long ani = Q;
 while(ani--){
  int x;
  cin>>x;
  a[x] += 1; }


  int cnt=0;
 for(int i=1;i<=n;i++){
     a[i] -= Q;
 }


 for(int i=1;i<=n;i++){
    if(a[i] > 0)
      cout<<"Yes"<<endl;
      else
      cout<<"No"<<endl;
    }


  return 0;
  }

