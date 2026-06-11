#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cfloat>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;
typedef long long ll;

int main(){
   int N,X,Y;
   cin >> N >> X >> Y;
   int ans[N];
   memset(ans,0,sizeof(ans));
   for (int i = 1; i <=N ; i++)
   {
      for (int j = i+1; j <= N; j++)
      {
         int dist = j-i;
         dist = min(dist,abs(X-i)+1+abs(Y-j));
         ans[dist]++;
      }
   }
   for(int i=1;i<N;i++){
      cout << ans[i]<<endl;
   }
   return 0;
}
