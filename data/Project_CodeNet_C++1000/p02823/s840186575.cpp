#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
using P = pair<int,int>;
using ivec = vector<int>;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }


const int MOD=1000000007;
int INF=100100100100100;
signed main(){
  int n;cin>>n;
  int a,b;cin>>a>>b;
  if(a<b)swap(a,b);
  if((a-b)%2==0){
    cout<<(a-b)/2<<endl;
    return 0;
  }
  cout<<min(b-1,n-a)+(a-b+1)/2<<endl;
  
  return 0;
}