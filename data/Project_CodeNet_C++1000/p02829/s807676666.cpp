#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
   int a, b;
   cin >> a;
   cin >> b;
   if(a == 1 && b == 2 || a == 2 && b == 1) cout << 3 << endl;
   else if(a == 1 && b == 3 || a == 3 && b == 1) cout << 2 << endl;
   else cout << 1 << endl;
}