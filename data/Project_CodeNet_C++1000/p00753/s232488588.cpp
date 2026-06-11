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

#define MAX 123456 * 2 + 1

vector< bool > p(MAX, true);

int main() {

    p[0] = p[1] = false;
    for(int i = 2; i * i < MAX; i++)
        for(int j = i + i; j < MAX; j += i)
            p[j] = false;

    int n;
    while(cin >> n, n) {
        int cnt = 0;
        for(int i = n + 1; i <= n + n; i++) {
            if(p[i]) cnt++;
        }
        cout << cnt << endl;
    }
}