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
  int i,h[100010],sum=0,ans=0;
  int n;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> h[i];
  }
  for(i=1;i<n;i++){
    if(h[i-1]>=h[i]){
      sum++;
    }
    else{
      ans=max(ans,sum);
      sum=0;
    }
  }
  ans=max(ans,sum);
  cout << ans << endl;
  return 0;
}