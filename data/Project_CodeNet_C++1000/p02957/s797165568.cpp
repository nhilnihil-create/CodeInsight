#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
   ll a,b;
   cin>>a>>b;
   if((a-b)%2)cout<<"IMPOSSIBLE"<<endl;
   else cout<<abs(b-a)/2+min(a,b)<<endl;
}