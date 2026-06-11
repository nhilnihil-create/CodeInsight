#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
#include<functional>
#include<deque>
#include<list>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll a,b;
  cin >> a >> b;
  if((a+b)%2==1){
    cout << "IMPOSSIBLE" << endl;
  }
  else{
    cout << (a+b)/2 << endl;
  }
  return 0;
}