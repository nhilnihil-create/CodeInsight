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
int gcd(int a, int b){
   if(a>b)return gcd(b,a);
   if(b%a==0) return a;
   else return gcd(b%a,a);
}

int main(){
   int N,M;
   cin >> N >>M;
   int a[N];
   long long k=1;
   for (int i = 0; i < N; i++)
   {
      cin >> a[i];
   }
   for (int i = 0; i < N; i++)
   {
      k *= (a[i]/2)/gcd(a[i]/2, k);
      if(k > M){
         cout << 0 << endl;
         return 0;
      }
   }
   for(int i = 0 ; i < N; i++){
      if((k/(a[i]/2))%2==0){
         cout << 0 << endl;
         return 0;
      }
   }
   cout << ((M/k)+1)/2 << endl;
   return 0;
}
