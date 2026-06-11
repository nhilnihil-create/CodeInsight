#include <iostream>
#include <vector>
#include <bitset>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>

using namespace std;
typedef long long ll;

struct arm{
  ll l;
  ll r;
};

int main(){
  int N;
  cin >> N;
  vector<arm> x(N);

  for(int i=0;i<N;i++){
    ll a,b;
    cin >> a >> b;
    x[i].l=a-b;
    x[i].r=a+b;
  }

  sort(x.begin(), x.end(), [](arm al,arm ar){
      if(al.r!=ar.r) return al.r<ar.r;
      else return al.l<ar.l;
    });

  int ans=0;
  ll cur=-2e9;
  for(int i=0;i<N;i++){
    if(cur<=x[i].l){
      ans++; cur=x[i].r;
    }
  }

  cout << ans << endl;

  return 0;
}