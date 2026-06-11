#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
 
int main(){
    int x, y, z;
    cin >> x >> y >> z;
    int temp;
    temp = x;
    x = y;
    y = temp;
    temp = x;
    x = z;
    z = temp;
    cout << x << " " << y << " " << z << endl;

    return 0;
}