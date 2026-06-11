#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
int k,x;
cin >> k >> x;
int a = x - k + 1;
int b = x + k - 1;
if(a < -1000000) a = -1000000;
if(b > 1000000) b = 1000000;
for(int i = a; i <= b; i++) cout << i << " ";
cout << endl;

}
  
