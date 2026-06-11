#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll=long long;

int main(){
 int n,m,sum=0;
 cin >> n >> m;
 vector<int> a(m);
 rep(i,m){
   cin >> a[i];
   sum += a[i];
 }
 if(sum>n) cout << -1 << endl;
 if(sum<=n) cout << n-sum << endl;
}
 