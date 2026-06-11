#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
 ll a,b,n; cin >> a >> b >> n;
 ll p;
 if(n<b)p=n;
 else{
   ll d=n/b; p=d*b-1;
 }
 ll flr1=(a*p)/b; ll flr2=p/b;
 ll ans=flr1-a*flr2;
 cout << ans << endl;
}
