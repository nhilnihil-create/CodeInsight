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
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  ll w,h,x,y;
  cin >> w >> h >> x >> y;
  double ans1=(double)w*(double)h/2;
  int ans2=0;
  if(x*2==w && y*2==h){
    ans2=1;
  }
  printf("%.12lf %d\n",ans1,ans2);
  return 0;
}