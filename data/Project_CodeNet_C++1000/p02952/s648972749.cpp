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
int digit(int n){
  int ans=0;
  while(n>0){
    ans++;
    n=n/10;
  }
  return ans;
}
int main(){
  int n,i;
  cin >> n;
  int ans=0;
  for(i=1;i<=n;i++){
    if(digit(i)%2==1){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}