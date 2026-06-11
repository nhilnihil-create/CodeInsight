#include <bits/stdc++.h>
#define rep(i,n) for (int (i) = 0; (i) < (n); i++)
#define ll long long
using namespace std;

int main() {
  int N,M,X;
  cin >> N >> M >> X;
  if(N+M+X>21){
    cout << "bust";
  }
  else{
    cout << "win";
  }
}