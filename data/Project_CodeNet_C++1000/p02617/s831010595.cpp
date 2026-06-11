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
  ll n,i,u,v;
  cin >> n;
  ll ans=0;
  for(i=1;i<=n;i++){
    ans+=i*(n-i+1);
  }
  for(i=0;i<n-1;i++){
    cin >> u >> v;
    if(u>v){
      swap(u,v);
    }
    ans=ans-(u-1)-(n-v);
    ans=ans-(u-1)*(n-v);
    ans--;
  }
  cout << ans << endl;
}