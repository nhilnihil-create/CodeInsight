#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

int main(){
  ll N;
  cin >> N;
  ll a[N];
  ll sum=0;
  for(ll i=0;i<N;i++){
    cin >> a[i];
    sum ^= a[i];
  }
  for(ll i=0;i<N;i++){
    cout << ll(sum ^ a[i]) << endl;
  }
}
