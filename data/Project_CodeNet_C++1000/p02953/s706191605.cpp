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
  int n,h[100010],i;
  cin >> n;
  for(i=0;i<n;i++){
    cin >> h[i];
  }
  for(i=0;i<n-1;i++){
    if(h[i]>h[i+1]){
      if(h[i]-h[i+1]>1){
        printf("No\n");
        return 0;
      }
      else{
        h[i+1]++;
      }
    }
  }
  printf("Yes\n");
  return 0;
}