#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793
 
   
int main(){
    int x;
    cin >> x; 
    ll a=x/__gcd(x,360)*360;
    int ans=a/x;
    cout << ans << endl;
} 