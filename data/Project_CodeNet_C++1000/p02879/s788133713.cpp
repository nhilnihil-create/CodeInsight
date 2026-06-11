#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define rep(i,n) for (int i=0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int a, b;
    cin >> a >> b;
    if (a > 9 || b > 9){
        cout << -1 << endl;
    } else {
        cout << a * b << endl;
    }
    return 0;
}