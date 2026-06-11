#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(void){
    int N;
    string C;
    cin >> N >> C;
    int w=0, r=0, r_origin=0;
    rep(i,N) if(C.at(i)=='R') r_origin++;
    rep(i,r_origin) if(C.at(i)=='W') w++;

    cout << w << endl;

    return 0;
}