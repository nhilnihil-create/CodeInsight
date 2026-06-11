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

int gcd(int a,int b){
   if(b<a) return gcd(b,a);
   if(b%a==0) return a;
   return gcd(b%a,a);
}

int main(){
   int  X;
   cin >> X;
   int g = gcd(X,360);
   cout << 360*X/g/X << endl;
   return 0;
}
