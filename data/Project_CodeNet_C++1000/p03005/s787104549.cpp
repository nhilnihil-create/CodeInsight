#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793




int main(){
   int n,k;
   cin >> n >> k;
   if(k==1)cout << 0 << endl;
   else{
   int x=n-(k-1);
   cout << x-1 << endl;
   }
}