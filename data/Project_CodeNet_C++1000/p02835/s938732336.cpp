#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
   int a, b, c;
   cin >> a >> b >> c;
   int d = a + b + c;
   if(d >= 22) cout << "bust" << endl;
   else cout << "win" << endl;
}