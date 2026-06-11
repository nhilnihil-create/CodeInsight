#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(n) begin(n),end(n)
using ll = long long;
using P = pair<int,int>;

int main() {
    long double a, b, c;
    cin >> a >> b >> c;
    if(4*a*b < pow((c-a-b),2.0) && (c-a-b)>0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}