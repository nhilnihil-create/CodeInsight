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
int main(){
  fast();
  int n;
  cin>>n;
  vector<ll> v(n);
  fr(i,n)cin>>v[i];
  int ans = 0;
  sort(v.begin(),v.end());
  fr(i,n-2)
    frs(j,i+1,n-1)
    	frs(k,j+1,n){
  if(v[i]!=v[j]&&v[j]!=v[k]&&v[k]!=v[i]&&v[i]+v[j]>v[k])ans++;
  }
  cout<<ans;
 return 0;
  
}


