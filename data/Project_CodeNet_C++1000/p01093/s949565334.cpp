#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>

int main()
{
  int n;
  while(scanf("%d",&n)==1){
      if(n==0){
          break;
      }
      else{
          int a[1010];
          for(int i=0;i<n;i++){
              scanf("%d",&a[i]);

          }
          int step = 10000000;
          for(int i=0;i<n-1;i++){
              for(int j=i+1;j<n;j++){
                  if(abs(a[i]-a[j])<step){
                      step = abs(a[i]-a[j]);
                  }
              }
          }
          printf("%d\n",step);

      }

  }


    return 0;
}
