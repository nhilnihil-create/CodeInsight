#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD =1000000007;
//

signed main() {
 int n,a,b;
 cin>>n>>a>>b;
 if((a-b)%2==0){
     cout<<abs(a-b)/2;
     return 0;
 }
 if(a>b)swap(a,b);
 cout<<min(a+(b-a-1)/2,n-b+1+(b-a-1)/2);
 return 0;
}
