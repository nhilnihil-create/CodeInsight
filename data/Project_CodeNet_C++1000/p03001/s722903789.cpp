#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    double w, h, x, y;
    cin >> w >> h >> x >> y;

    int o = 0;
    if(w/2==x&&h/2==y){
        o = 1;
    }
    cout << (double)w*h/2.0 <<" "<<  o << endl;
    return 0;
}