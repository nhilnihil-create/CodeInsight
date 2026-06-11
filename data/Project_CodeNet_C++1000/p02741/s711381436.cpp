#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define Rep(i,s,n) for(int i=s;i<n;i++)
#define fi first
#define se second
#define all(c) c.begin(),c.end()
typedef long long int ll;
typedef pair<int, int> P;
typedef long double ld;
void Ans(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}

const ll INF=1001001001;
const ll mod=1000000007;

int main(){
  int k;
  cin>>k;
  
  vector<int> v={1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1,
  15, 2, 2, 5, 4, 1, 4, 1, 51};
  
  cout<<v[k-1]<<endl;
}
