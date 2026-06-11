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
#define fr(i,n) for(int i=0;i<(int)n;i++)
#define frs(i,a,b) for(int i = a;i<b;i++)
#define meme(a,b,c) memset(a,b,sizeof(c)); //works only for 0 and -1
bool isPrime(int x){
for(int i=2;i*i<=x;i++){
if(x%i==0)return false;
}
  return true;
}
int main(){
  fast();
 ll n;
  cin>>n;int total = 0;
  for(int i=0;i<n;i++){
    total = (total*10+7)%n;
      if(total==0){cout<<i+1;return 0;}
    
  }
  cout<<-1;
 return 0;
  
}


