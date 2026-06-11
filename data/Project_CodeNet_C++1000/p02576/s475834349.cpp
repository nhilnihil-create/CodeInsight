#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

int main(){
  int n,x,t;
  cin>>n>>x>>t;
  
  cout<<(n+x-1)/x*t<<endl;
  return 0;
}
