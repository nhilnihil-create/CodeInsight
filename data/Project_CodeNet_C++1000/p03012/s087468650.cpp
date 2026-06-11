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
  int n,a[110],i,j;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  int ans=(1<<29);
  for(i=0;i<n;i++){
    int sum=0,sum1=0;
    for(j=0;j<i;j++){
      sum+=a[j];
    }
    for(j=i;j<n;j++){
      sum1+=a[j];
    }
    ans=min(ans,abs(sum-sum1));
  }
  cout << ans << endl;
  return 0;
}