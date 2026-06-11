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
  ll N,K,S;
  cin >> N >> K >> S;
  if(S==1){
    for(int i=0;i<K;i++) cout << 1 << " ";
    for(int i=0;i<N-K;i++) cout << 2 << " ";
  }else if(S==2){
    for(int i=0;i<K;i++) cout << 2 << " ";
    for(int i=0;i<N-K;i++) cout << 3 << " ";
  }else{
    for(int i=0;i<K;i++) cout << S << " ";
    for(int i=0;i<N-K;i++) cout << S-1 << " ";
  }
  cout << endl;

  return 0;
}