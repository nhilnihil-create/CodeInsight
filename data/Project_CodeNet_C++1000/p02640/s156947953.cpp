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
    int x,y; cin>>x>>y;
    int t,k;
    t = y-2*x;
    k = 4*x-y;
    string out;
    if(t>=0&&k>=0&&t%2==0&&k%2==0) out = "Yes";
    else out = "No";
    cout << out << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    