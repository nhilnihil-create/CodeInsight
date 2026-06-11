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
#define meme(a,b) memset(a,b,sizeof(a)); //works only for 0 and -1
void solve(){
int x,n;
cin>>x>>n;
int arr[n];
fr(i,n)cin>>arr[i];
sort(arr,arr+n);
int k = 0;
while(1){
int x1 = x+k;
int x2 = x-k;
if(binary_search(arr,arr+n,x2)==false){cout<<x2;return;}
if(binary_search(arr,arr+n,x1)==false){cout<<x1;return;}
k++;
}
}
int main(){
  fast();
// int t;cin>>t;
// while(t--){
    solve();
// }
 return 0;
}
