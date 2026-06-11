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
  int n,p[30],i;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> p[i];
  }
  int ans=0;
  for(i=1;i<n-1;i++){
    vector<int> x;
    x.push_back(p[i]);
    x.push_back(p[i+1]);
    x.push_back(p[i-1]);
    sort(x.begin(),x.end());
    if(x[1]==p[i]){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}