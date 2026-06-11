#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <map>
#include <cmath>
#include <stack>

using namespace std;

typedef long long ll;
int main() {
    ll n; cin >> n;
    int j = 0;
    stack<char> sk;
    while (n > 0) {
        if(n % 26 == 0) {
            // break;
            sk.push('z');
            n--;
            n /= 26;
            continue;
        }
        j = (n-1) % 26 ;
        // if(j == -1) j = 25;
        sk.push('a' + j);
        n /= 26;
    }
    while (!sk.empty())
    {
        cout << sk.top();
        sk.pop();
    }


}