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
#include<iomanip>
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
#define fr(i,n) for(int i=0;i<(int)n;i++)
#define frs(i,a,b) for(int i = a;i<b;i++)
#define meme(a,b,c) memset(a,b,sizeof(c)); //works only for 0 and -1
int main(){
  fast();
  ll n;
  cin>>n;
  ll arr[n];
  fr(i,n)cin>>arr[i];
  ll sum = 0;
  frs(i,1,n){
  if(arr[i]<arr[i-1]){sum+= (arr[i-1]-arr[i]);arr[i] = arr[i-1];}
  }
  cout<<sum;
 return 0;
  
}


