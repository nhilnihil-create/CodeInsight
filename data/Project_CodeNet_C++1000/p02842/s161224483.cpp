#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define INF 1000000007
// cin.eof() 入力個数の問題
int main(){
int n;
cin>>n;
for(int i=1;i<100007;i++){
   double cost;
   cost=(double)i*1.08;
   int ans=cost;
   if(ans==n){
       cout<<i<<endl;
       return 0;
   }
}
cout<<":("<<endl;

  return 0;
}
