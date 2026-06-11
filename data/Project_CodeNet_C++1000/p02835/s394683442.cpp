#include <bits/stdc++.h>
using namespace::std;
#define int long long

#define all(x) (x).begin(), (x).end()
#define inf (sizeof(int) == 4 ? (int)1E9 : (int)1E18)

template<class T> istream& operator>>(istream& I, vector<T>& v) {for (T &e: v) I >> e; return I;}

void _main() {
        int a,b,c; cin >>a>>b>>c;
        if (a+b+c>=22)cout<<"bust";
        else cout <<"win";
}



signed main() {
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int _t = 1;
//        cin >> _t;
        while (_t--) _main();
        return 0;
}