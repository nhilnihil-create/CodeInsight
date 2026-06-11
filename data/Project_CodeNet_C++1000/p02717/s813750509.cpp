#include <bits/stdc++.h>
#include <string>
using namespace std;
typedef long long ll;
int main(){
    int x, y, z; cin >> x >> y >> z;
    swap(x, y); swap(x, z);
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    return 0;
}