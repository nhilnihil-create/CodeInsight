#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {

    int N;
    cin >> N;

    double m = N / 1.08;
    int ce = ceil(m);
    int fl = floor(m);

    int ce_tax = floor(ce*1.08);
    int fl_tax = floor(fl*1.08);
    if(ce_tax == N){
        cout << ce << endl;
        return 0;
    } else if(fl_tax == N){
        cout << fl << endl;
        return 0;
    } else {
        cout << ":(" << endl;
        return 0;
    } 
    return 0;
}