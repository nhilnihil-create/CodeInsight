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
#define mod 1000000007
#define fr(i,n) for(int i=0;i<n;i++)
#define frs(i,a,b) for(int i = a;i<b;i++)
#define meme(a,b,c) memset(a,b,sizeof(c)); //works only for 0 and -1
int main(){
  fast();
int n,m,k;
cin>>n>>m>>k;
ll arr1[n],arr2[m];
fr(i,n)cin>>arr1[i];
fr(i,m)cin>>arr2[i];
vector<ll> v1(n+1),v2(m+1);
fr(i,n){
   v1[i+1] = v1[i] + arr1[i];
}
fr(i,m){
   v2[i+1] = v2[i] + arr2[i];
}
ll total = 0;
fr(i,n+1){
  ll other = k - v1[i];
  if(other<0)continue;
  ll l = lower_bound(v2.begin(),v2.end(),other)-v2.begin();
  if(l>m||v2[l]>other)l--;
  total = max(total,i+l);
}
cout<<total;
 return 0;
}
