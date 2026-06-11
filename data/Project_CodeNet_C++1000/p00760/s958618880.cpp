#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstdio>
#include<cstring>
#include<sstream>
#define X first
#define Y second
#define pb push_back

using namespace std;

int n,y,m,d,sum,days;

int main(){
  scanf("%d",&n);
  while(n--){
    scanf("%d %d %d",&y,&m,&d);
    sum=0;
    for(;y<1000;y++){
      for(;m<=10;m++){
        days=19+(y%3==0 || m%2==1);
        for(;d<=days;d++){
          sum++;
        }
        d=1;
      }
      m=1;
    }
    printf("%d\n",sum);
  }
  return 0;
}