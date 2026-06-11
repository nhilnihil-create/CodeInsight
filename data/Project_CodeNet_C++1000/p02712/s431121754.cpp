#include <vector>
#include <iostream>
#include <string>
using namespace std;
using ll = long long;
int main(){
  ll N;
  ll res=0;
  cin >> N;
  for(ll i=1;i<N+1;i++){
    if(i%3==0)continue;
    if(i%5==0)continue;
    res+=i;
  }
  cout << res << endl;

}