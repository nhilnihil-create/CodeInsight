#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
 
   
int main(){
 int n;
 cin >> n;
 int ans=-1;
 for(int i=1;i<=50000;i++){
   int v=i*108/100;
   if(v==n){
     ans=i;
     break;
   }
 }
 if(ans<0)cout << ":(" << endl;
 else cout << ans << endl;
} 
    