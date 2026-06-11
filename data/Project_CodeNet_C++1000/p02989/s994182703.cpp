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
  int n,i;
  cin >> n;
  vector<int> x(n);
  for(i=0;i<n;i++){
    cin >> x[i];
  }
  sort(x.begin(),x.end());
  cout << x[n/2]-x[n/2-1] << endl;
  return 0;
}