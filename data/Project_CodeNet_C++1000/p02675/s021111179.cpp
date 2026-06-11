#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

lli n;

int main(void){
    cin >> n;
    lli v = n%10;
    if(v == 2 || v == 4 || v == 5 || v == 7 || v == 9) cout << "hon" << endl;
    else if(v == 0 || v == 1 || v == 6 || v == 8) cout << "pon" << endl;
    else if(v == 3) cout << "bon" << endl; 
    return 0;
}
