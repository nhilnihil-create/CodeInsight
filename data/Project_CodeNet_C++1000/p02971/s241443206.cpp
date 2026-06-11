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
  int n,a[200010],i,b[200010];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> a[i];
    b[i]=a[i];
  }
  sort(b,b+n,greater<int>() );
  for(i=0;i<n;i++){
    if(a[i]!=b[0]){
      cout << b[0] << endl;
    }
    else{
      cout << b[1] << endl;
    }
  }
  return 0;
}