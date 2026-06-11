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
  ll S;
  cin>>S;
  if(S==1000000000000000000){
    cout<<0<<" "<<0<<" "<<1000000000<<" "<<0<<" "<<1000000000<<" "<<1000000000<<endl;
    return 0;
  }
  ll A=S/1000000000;
  ll B=S%1000000000;
  cout<<0<<" "<<0<<" "<<1000000000<<" "<<1<<" "<<1000000000-B<<" "<<A+1<<endl;
}