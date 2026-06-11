#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(void){
  ll n;
  cin >> n;
  ll ans=0,a,p=0;
  for (int i=0; i<n; i++){
    cin >> a;
    if (a<p) {
      ans+=p-a;
    }
    else p=a;
  }

  cout << ans << endl;
}