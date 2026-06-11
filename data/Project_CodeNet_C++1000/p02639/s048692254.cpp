#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()

void _main(){
    vector<int> x(5); rep(i,5) cin >> x[i];
    int outi = find(ALL(x),0)-x.begin() + 1;
    cout << outi << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    