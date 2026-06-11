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
typedef vector< vector<int> > VVI;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back

int main(){
  int H,W,A,B;
  cin>>H>>W>>A>>B;
  rep(i,H){
    rep(j,W){
      if((i<B&&j<A)||(i>=B&&j>=A)) cout<<0;
      else cout<<1;
    }
    cout<<endl;
  }
}