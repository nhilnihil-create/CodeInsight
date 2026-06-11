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
  int i,n,a[20],b[20],c[20];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
  }
  int ans=0;
  for(i=0;i<n;i++){
    cin >> b[i];
    ans+=b[i];
  }
  for(i=0;i<n-1;i++){
    cin >> c[i];
  }
  for(i=0;i<n-1;i++){
    if(a[i]+1==a[i+1]){
      ans+=c[a[i]-1];
    }
  }
  cout << ans << endl;
  return 0;
}