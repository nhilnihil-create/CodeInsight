#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <bitset>
#include <map>
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

/*
cin.tie(0);
ios::sync_with_stdio(false);
*/

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pi;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ddx[8]={-1,-1,0,1,1,1,0,-1};
int ddy[8]={0,1,1,1,0,-1,-1,-1};
bool debug=false;

/*---------------------------------------------------*/

#include <iostream>
using namespace std;

int main(){
  int n;
  int ans = 0;
  while(cin>>n){
    if(n==0)break;
    ans=0;
    for(int i=1;i<n;i++){
      int sum=0;
        for(int j=i;j<n;j++){
	  sum+=j;
	  if(sum==n)ans++;
	  if(sum>=n)break;
        }
	//cout<<"sum: "<<i<<" "<<sum<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}

