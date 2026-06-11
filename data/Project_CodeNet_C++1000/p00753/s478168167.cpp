#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <tuple>
#include <unordered_map>
#include <list>
#include <numeric>
#include <utility>
#include <iterator>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <ctime>
#include <cassert>

#define INF 1000000000
#define LINF 9000000000000000000
#define mod 1000000007

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define REP(i,a,b) for(int i=(a);i<int(b);i++)
#define all(x) (x).begin(),x.end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long>vll;
typedef pair<int,int> pi;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

vector<int> sieve(int n){
  vector<int> ret;
  bool is_prime[n+1];
  memset(is_prime, true, sizeof(is_prime));
  is_prime[0]=is_prime[1]=false;
  for(int i=2;i<n+1;i++){
    if(is_prime[i]){
      ret.push_back(i);
      for(int j=2*i;j<n+1;j+=i)is_prime[j]=false;
    }
  }
  return ret;
}

int main(){
  int n;
  vector<int> prime1,prime2;
  while(cin>>n,n){
    prime1=sieve(n);
    prime2=sieve(n*2);
    cout<<prime2.size()-prime1.size()<<endl;
    prime1.clear();prime2.clear();
  }
  return 0;
}

