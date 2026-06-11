#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  double a,b,x; cin >> a >> b >> x;

  double v = a * a * b;
  double pi = acos(-1);

  if(x < v * 0.5){
    double theta = atan(a * b * b / 2.0 / x);
    cout << theta * 180 / pi  << endl;
  } else { 
    double p = (v-x) / ( a * a * 0.5);
    double theta = atan(p/a);
    cout << theta * 180 / pi << endl;
  }
}
