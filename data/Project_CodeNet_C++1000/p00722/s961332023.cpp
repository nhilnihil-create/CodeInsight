#include <map>
#include <set>
#include <list>
#include <cstdio>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

#define fr first
#define sc second
#define mp make_pair

typedef long long int64;
typedef pair< int, int > iP;
typedef pair< iP, int > iiP;

const int INF = 2 << 28;
const double EPS = 1e-10;

int main() {

    vector< bool > p(1000001, true);
    p[0] = p[1] = false;
    for(int i = 2; i * i < 1000001; i++)
        for(int j = i + i; j < 1000001; j += i)
            p[j] = false;

    int a, d, n;
    while(cin >> a >> d >> n, d) {
        int cnt = 0;
        for(int i = 0; ; i++) {
            if(p[a + d * i]) cnt++;
            if(cnt == n) {
                cout << a + d * i << endl;
                break;
            }
        }
    }
}