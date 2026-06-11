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
  cin >> n ;
  for(i=0;i<n-1;i++){
    cin >> a[i];
  }
  int ans=0;
  for(i=0;i<n;i++){
    if(i==0){
      ans+=a[i];
    }
    else if(i==n-1){
      ans+=a[i-1];
    }
    else{
      ans+=min(a[i-1],a[i]);
    }
  }
  cout << ans << endl;
  return 0;
}