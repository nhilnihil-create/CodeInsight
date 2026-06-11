#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
 
   
int main(){
 int a,b;
 cin >> a >> b;
 int ans=-1;
 for(int i=1;i<=100000;i++){
   int x=(i*8)/100;
   int y=i/10;
   if(a==x && b==y){
     ans=i;
     break;
   }
 }
 cout << ans << endl;
} 
    