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
#define beg begin()
#define end end()

void _main(){
    int n,m; cin >> n >> m;
    auto check = [](int x,map<int,int>& digitnums){
        vector<int> digitx;
        if(x==0) digitx.push_back(x);
        while(x){
            digitx.push_back(x%10);
            x /=10;
        };
        reverse(digitx.beg,digitx.end);
        for(auto dnum : digitnums){
            if(digitx[dnum.first-1]!=dnum.second) return false;
        }
        return true;
    };
    auto mainn = [&](){
        map<int,int> digitnums;
        rep(i,m){
            int s,c; cin >> s >> c;
            auto ite = digitnums.find(s);
            if(ite != digitnums.end && digitnums[s] != c) return -1;
            else digitnums.emplace(s,c);
        }
        int mi=0;if(n>1) mi = pow(10,n-1);
        int ma= pow(10,n);
        int x;
        for (x = mi; x < ma; x++)
        {
            if(check(x,digitnums)) return x;
        }
        return -1;
    };
    cout << mainn() << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    