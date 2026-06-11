#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 10000000000 + 7;

int main(){
  cout << setprecision(10);
  int a,b; cin >> a >> b;

  if(a <= 9 && b <= 9){
    cout << a * b << endl;
  } else  {
    cout << -1 << endl;
  }

}
