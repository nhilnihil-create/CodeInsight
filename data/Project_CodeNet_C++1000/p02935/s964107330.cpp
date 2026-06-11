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
  vector<double> v(n);
  for(i=0;i<n;i++){
    cin >> v[i];
  }
  sort(v.begin(),v.end());
  double ans=(v[0]+v[1])/2;
  for(i=2;i<n;i++){
    ans=(ans+v[i])/2;
  }
  printf("%.12lf\n",ans);
  return 0;
}