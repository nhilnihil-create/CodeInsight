#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
   int h, a;
   cin >> h >> a;
   if(h%a != 0) cout << h/a +  1 << endl;
   else if(h%a == 0) cout << h/a << endl;
}