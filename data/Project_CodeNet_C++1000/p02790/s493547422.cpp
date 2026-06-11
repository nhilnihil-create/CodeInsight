#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;

int main(){
    int a,b;
    cin >> a >> b;
    string sa,sb;
    for(int i = 0;i < b;i++) sa += to_string(a);
    for(int i = 0;i < a;i++) sb += to_string(b);
    if(sa <= sb) cout << sa << endl;
    else cout << sb << endl;
}