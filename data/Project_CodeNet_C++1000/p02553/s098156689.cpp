#include <bits/stdc++.h>
#include <set>
using namespace std;

int main(){

   long long a, b, c,d;
   cin >> a >> b >> c >> d;

   long long ad = a * d;
   long long ac = a * c;
   long long bc = b * c;
   long long bd = b * d;

   long long max_num = max({ad, ac, bc, bd});
   
   cout << max_num << endl;

}
