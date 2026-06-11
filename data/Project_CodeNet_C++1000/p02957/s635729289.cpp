#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
   int a,b,k;
   cin>>a>>b;
   k=(a+b)/2;
   if(a%2==0&&b%2==0) cout<<k<<endl;
   else if(a%2!=0&&b%2!=0) cout<<k<<endl;
   else cout<<"IMPOSSIBLE"<<endl;
}