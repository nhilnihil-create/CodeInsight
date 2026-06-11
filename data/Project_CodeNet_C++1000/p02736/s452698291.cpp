#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<string> VS;
typedef vector< vector<int> > VVI;
typedef vector< vector<ll> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  int ans=0;
  int cnt=0;
  rep(i,S.size()){
    if(S[i]=='2'){
      cnt++;
      ans+=(i==((N-1)&i));
      ans%=2;
    }
  }
  if(ans){
    cout<<1<<endl;
    return 0;
  }
  if(cnt){
    cout<<0<<endl;
    return 0;
  }
  rep(i,S.size()){
    if(S[i]=='3'){
      ans+=(i==((N-1)&i));
      ans%=2;
    }
  }
  ans*=2;
  cout<<ans<<endl;
}