#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using ld = long double;
const ld eps = 1.0e-9; // 許容される誤差

ld mysqrtl(ld x)
{
  ld a = sqrt((double)x); // 近似値
  do {
    a = (a + x/a) / 2.0L;
  } while (fabsl(x - a*a) > eps);
  return a;
}


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    ld a,b,c;
    cin >> a >> b >> c;
    ld eps = 1.0E-14;
    if(sqrt(a)+sqrt(b)+eps<sqrt(c)){
        cout << "Yes" << "\n";
        return 0;
    }else{
        cout << "No" << "\n";
        return 0;
    }
}   