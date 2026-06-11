#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include <initializer_list>
#include<unordered_set>
#include<map>
#include<cmath>
#include <iterator>
#include<stack>
#include<queue>
#include <iomanip>
#include<math.h>
#include <limits.h>
#include <numeric>
#include <functional>
#include<fstream>
#define ll long long

#define sondos ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;

   int x, y, c = 0;

   int main() {

       sondos

           int a, b, c; cin >> a >> b >> c;
       cout << (((c / max(a, b))* max(a, b)  )>= c ? (c / max (a, b)) : ((c / max(a, b)) + 1));

            
           return 0;
   }