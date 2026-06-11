/**********************************************************************************************
******************************AUTHOR:**********************************************************
****************************ASHISH RANJAN******************************************************
***********************************************************************************************/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<chrono>
#include<vector>
#include<string>
#include<cstring>
using namespace std;
using namespace std::chrono;
/*
auto start = high_resolution_clock::now();
auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
*/
#define fast() ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
const int M = 1e9 + 7;
#define fr(i,n) for(int i=0;i<n;i++)
#define frs(i,a,b) for(int i = a;i<b;i++)
#define meme(a,b) memset(a,b,sizeof(a)); //works only for 0 and -1
ll mod(long long x){
 return (x%M+M)%M;
}
ll add(long long a,long long  b){
return mod(mod(a)+mod(b));
}
ll mul(long long a,long long b){
return mod(mod(a)*mod(b));
}
ll minu(long long a,long long b){
return mod(mod(a)-mod(b));
}
ll modPow(ll a,ll b){
if(b==0)return 1LL;
if(b==1)return a%M;
ll res= 1;
while(b){
if(b%2==1)
res = mul(res,a);
a = mul(a,a);
b/=2;
}
return res;
}
void solve(){
int n;
cin>>n;
long long arr[n];
  long long mul = 1;
  fr(i,n)cin>>arr[i];
  fr(i,n)if(arr[i]==0){cout<<"0";return ;}
  fr(i,n){
  if(arr[i]<=1000000000000000000LL/mul){
  mul *= arr[i];
  }
    else {cout<<"-1";return ;} 
  }
  cout<<mul;
}
int main(){
  fast();
//  int t;cin>>t;
//  while(t--){
    solve();
    cout<<endl;
//  }
 return 0;
}
