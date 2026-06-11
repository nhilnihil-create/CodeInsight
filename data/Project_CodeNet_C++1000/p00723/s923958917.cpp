#include <iostream>
#include <cstdio>
#include <iomanip>

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <utility>

#include <numeric>
#include <algorithm>
#include <functional>

#include <cctype>

#include <complex>
#include <string>
#include <sstream>

using namespace std;

#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define rep(i,n) for(unsigned int i=0;i<(n);i++)
#define tr(it,container) for(typeof(container.begin()) it = container.begin(); \
                                                  it != container.end(); ++it)
#define mp(a,b) make_pair((a),(b))

typedef long long ll;
typedef complex<double> P;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,-1,0,1};
const double EPS = 1e-9;
const int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int daysleap[] = {31,29,31,30,31,30,31,31,30,31,30,31};

int main(){
    int m;
    cin >> m;
    rep(k,m){
        string s;
        cin >> s;
        set<string> S;
        for(int i=1;i<s.length();i++){
            string h = s.substr(0,i);
            string t = s.substr(i);
            string rh = h;
            string rt = t;
            reverse(all(rh));
            reverse(all(rt));
            S.insert(h+t);
            S.insert(t+h);
            S.insert(rh+t);
            S.insert(t+rh);
            S.insert(h+rt);
            S.insert(rt+h);
            S.insert(rh+rt);
            S.insert(rt+rh);
        }
        cout << S.size() << endl;
    }
    return 0;
}