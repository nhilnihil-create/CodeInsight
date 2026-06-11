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
  ll i,n,a[100010],b[100010];
  cin >> n;
  ll sum=0;
  for(i=0;i<n+1;i++){
    cin >> a[i];
    sum+=a[i];
  }
  for(i=0;i<n;i++){
    cin >> b[i];
  }
  for(i=0;i<n;i++){
    if(a[i]>=b[i]){
      a[i]=a[i]-b[i];
    }
    else{
      b[i]=b[i]-a[i];
      a[i]=0;
      a[i+1]=max(ll(0),a[i+1]-b[i]);
    }
  }
  ll sum1=0;
  for(i=0;i<n+1;i++){
    sum1+=a[i];
  }
  cout << sum-sum1 << endl;
  return 0;
}