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
 
int main(){
  int N,K;
  cin >> N >> K;

  vector<int> a(N);
  for(auto &ai:a) cin >> ai;

  map<int,int> v;

  int cur=0;
  int scur=0;
  for(cur=0;cur<min(N,K-1);cur++){
    scur+=a[cur]; scur%=K;
    v[scur-cur-1]++;
    //cout << scur-cur-1 << endl; 
  }
  ll ans=v[0];

  
  int rcur=0;
  for(int i=0;i<N;i++){
    rcur+=a[i]; rcur%=K;
    v[rcur-i-1]--;
    //cout << "# " << rcur-i-1 << endl; 
    if(cur<N){
      scur+=a[cur]; scur%=K;
      v[scur-cur-1]++;
      //cout << scur-cur-1 << endl; 
      cur++;
    }
    ans+=v[rcur-i-1]+v[rcur-i-1-K];
  }

  cout << ans << endl;
  
  return 0;
}
