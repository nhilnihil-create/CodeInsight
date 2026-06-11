#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
int main(){
  ll n,k,q;
  cin >> n >> k >> q;
  vector<ll> p(n);
  //for(int i = 0;i < n;i++)p[i] = 0;
  //cout << p[0] << endl;
  for(int i = 0;i < q;i++){
    ll in;
    cin >> in;
    in--;
    p[in]++;
  }
  for(int i = 0;i < n;i++){
    if(q - k < p[i])cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}