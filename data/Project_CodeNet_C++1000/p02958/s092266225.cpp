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
  int i,j,k,n,p[55],a[55];
  cin >> n;
  for(i=0;i<n;i++){
    cin >> p[i];
    p[i]--;
    a[i]=p[i];
  }
  for(i=0;i<n;i++){
    for(j=i;j<n;j++){
      swap(a[i],a[j]);
      int res=0;
      for(k=0;k<n;k++){
        if(k!=a[k]){
          res=1;
        }
      }
      if(res==0){
        cout << "YES" << endl;
        return 0;
      }
      for(k=0;k<n;k++){
        a[k]=p[k];
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}