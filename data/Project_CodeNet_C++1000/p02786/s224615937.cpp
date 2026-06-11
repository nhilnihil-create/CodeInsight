#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
 ll h;
 cin >> h;
 int n=0;
 ll a=1;
 while(a<=h){
   a*=2;
   n++;
 }
 ll ans=1;
 rep(i,n-1){
   ans=ans*2+1;
 }
 cout << ans << endl;
}