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
   int M;
   cin >> M;
   long long d[M];
   long long c[M];
   long long sum = 0;
   long long ans = 0;
   for(int i = 0 ; i < M; i++){
      cin >> d[i] >> c[i];
      sum+= d[i]*c[i];
      ans+=c[i];
   }
   cout << ans-1+(sum-1)/9<<endl;
   return 0;
}
