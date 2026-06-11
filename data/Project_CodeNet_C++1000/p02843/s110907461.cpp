#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int X;
    cin >> X;
    int list[6] = {100, 101, 102, 103, 104, 105};
    int a = X / list[0];
    if (X > a * list[5])
    {
        cout << 0 << endl;
    } else
    {
        cout << 1 << endl;
    }
    
    

  return 0;
}