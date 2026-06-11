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
  int i,n,x,l[110];
  cin >> n >> x;
  for(i=0;i<n;i++){
    cin >> l[i];
  }
  int d=0,sum=1;
  for(i=0;i<n;i++){
    d=d+l[i];
    if(d<=x){
      sum++;
    }
  }
  cout << sum << endl;
  return 0;
}