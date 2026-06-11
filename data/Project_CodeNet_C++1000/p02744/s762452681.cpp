#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

void dfs ( string a, int n, char max_char ) {
    if ( (int)a.length() == n ) {
        cout << a << endl;
        return;
    }
    for ( char c = 'a'; c <= max_char; ++c ) {
        string next = a + c;
        dfs ( next, n, ((c==max_char) ? max_char+1 : max_char) );
    }
    return ;
}

int main(){
    int n;
    cin >> n;
    dfs("", n, 'a');
    return 0;
}
