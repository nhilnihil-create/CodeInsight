#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
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
    int n;
    cin>>n;
    int a[n+8];
    Rep(i,1,n+1){
        cin>>a[i];
    }
    ll b[n+8];
  
  rep(i,n+1) b[i]=0;
  
  Rep(i,1,n+1){
    int j=n+1-i;
    int c=1;
    int now=0;
    while(j*c<=n){
      now+=b[j*c];
      c++;
    }
    now=now%2;
    if(now!=a[j]) b[j]=1;
    //cout<<j<<' '<<n<<endl;
  }
  
  int m=0;
  Rep(i,1,n+1){
    m+=b[i];
  }
  cout<<m<<endl;
  Rep(i,1,n+1){
    if(b[i]==1){
      cout<<i<<endl;
    }
  }
  //cout<<a[1]<<endl;
    
}

