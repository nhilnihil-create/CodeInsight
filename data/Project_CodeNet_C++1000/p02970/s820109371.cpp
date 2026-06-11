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
  int n,d;
  cin >> n >> d;
  d=d*2+1;
  if(n%d==0){
    cout << n/d << endl;
  }
  else{
    cout << n/d+1 << endl;
  }
  return 0;
}