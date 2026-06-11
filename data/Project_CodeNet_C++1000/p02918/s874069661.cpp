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
using namespace std;
typedef long long ll;
typedef pair<int,int> pll;
typedef pair<int,pll> P;
int main(){
  int i,n,k,t=0;
  string s;
  scanf("%d %d\n",&n,&k);
  cin >> s;
  for(i=1;i<n;i++){
    if(s[i-1]!=s[i]){
      t++;
    }
  }
  t++;
  t=t-k*2;
  if(t<1){
    t=1;
  }
  printf("%d\n",n-t);
  return 0;
}