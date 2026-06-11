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
int main(){
  fast();
ll n;
cin>>n;
string ans = "";
while(n){
ll k = n/26;
ll z = n%26;
if(z==0){
k--;
ans = (char)'z' + ans;
}
else{
ans = (char)(('a'+z-1))+ans;
}
n = k;
}
cout<<ans;
 return 0;
}
