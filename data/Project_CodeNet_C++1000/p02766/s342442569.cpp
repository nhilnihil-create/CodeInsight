#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
   int n, k;
   cin >> n >> k;
   int count = 0;
   while (n > 0)
   {
       n /= k;
       count += 1;
   }
   cout << count << endl;
   return 0;
}