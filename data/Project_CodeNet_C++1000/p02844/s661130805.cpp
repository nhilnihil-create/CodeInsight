#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <functional>
#include <string>
#include <cmath>  //sqrt 
#include <iomanip> //setprecision
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define MAX 1000001

void _main(){
    int out=0;
    int n; cin >> n;
    string s; cin >> s;
    for(int bi =0 ; bi < 1000 ; bi++){
        string ba = to_string(bi);
        while(ba.size()<3) ba.insert(0,"0");
        int flag=0;
        int bfiter=0;
        for(auto a: ba){
            auto iter = find(s.begin()+bfiter,s.end(),a);
            if(iter==s.end()) break;
            bfiter = iter-s.begin()+1;
            flag++;
        }
        if(flag==3) {
            out++;
        }
    }
    cout << out << endl;
    return;
}
int main() {
    cout << fixed << setprecision(10);
    _main();
    return 0;
}
    