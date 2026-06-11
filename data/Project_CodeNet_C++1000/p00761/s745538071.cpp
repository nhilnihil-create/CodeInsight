#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <math.h>
#include <string>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <stdlib.h>

using namespace std;

#define ll long long
#define ld long double
#define EPS 0.0000000001
#define INF 10000000000LL
#define rep(i,n) for(i=0;i<n;i++)

typedef pair<int,int> pii;
int i,j;

int main(void) {
  while(1){
    int n,l;
    cin>>n>>l;
    if(n==0 && l==0)break;
    char a[25][10]={};
    rep(i,l){
      a[0][l-1-i]=n%10;
      n/=10;
    }
    rep(i,20){
      char now[10]={};
      rep(j,l)
        now[j]=a[i][j];
      sort(now,now+l);
      char a_min[10]={};
      char a_max[10]={};
      rep(j,l){
        a_min[j]=now[j];
        a_max[l-j-1]=now[j];
      }
      int amin=0;
      int amax=0;
      int temp=1;
      for(j=l-1;j>=0;j--){
        amin+=a_min[j]*temp;
        amax+=a_max[j]*temp;
        temp*=10;
      }
      amax=amax-amin;
      amin=amax;
      for(j=l-1;j>=0;j--){
        a[i+1][j]=amax%10;
        amax/=10;
      }
      bool ans=false;
      rep(j,i+1)
        if(strcmp(a[j],a[i+1])==0){
          printf("%d %d %d\n",j,amin,i+1-j);
          ans=true;
          break;
        }
      if(ans)break;
    }

  }
  return 0;
}