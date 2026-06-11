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
  int i,n;
  cin >> n;
  vector<int> p(n);
  for(i=0;i<n;i++){
    cin >> p[i];
  }
  int ans=0,min=100000000;
  for(i=0;i<n;i++){
    if(min>p[i]){
      ans++;
      min=p[i];
    }
  }
  cout << ans << endl;
}