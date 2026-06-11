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
    int x,n; cin>>x>>n;
    vector<int> p(n); rep(i,n) cin >> p[i];
    int out;
    int mi = x;
    int pl = x;
    while(1){
        if(find(ALL(p),mi)==p.end()) {out = mi;break;}
        if(find(ALL(p),pl)==p.end()) {out = pl;break;}
        mi--;pl++;
    }
    cout << out << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    