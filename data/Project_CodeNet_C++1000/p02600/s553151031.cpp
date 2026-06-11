#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=2019;


int main(){
    int x; cin >> x;
    if(400 <= x && x <= 599) cout << 8 << endl;
    else if(x <= 799) cout << 7 << endl;
    else if(x <= 999) cout << 6 << endl;
    else if(x <= 1199) cout << 5 << endl;
    else if(x <= 1399) cout << 4 << endl;
    else if(x <= 1599) cout << 3 << endl;
    else if(x <= 1799) cout << 2 << endl;
    else if(x <= 1999) cout << 1 << endl;
    return 0;
}