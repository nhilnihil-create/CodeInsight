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
  int n,a[110],i;
  cin >> n;
  double ans=0;
  for(i=0;i<n;i++){
    cin >> a[i];
    double b=a[i];
    ans+=1/b;
  }
  printf("%.12lf\n",1/ans);
  return 0;
}