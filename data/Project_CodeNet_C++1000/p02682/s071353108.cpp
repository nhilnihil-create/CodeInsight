#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
   ll a,b,c,k;
   cin >> a >> b >> c >> k;

   if(k <= a)cout << k << endl;
   else if( k <= a+b)cout << a << endl;
   else cout << a-(k-a-b) << endl;
   
}
       
