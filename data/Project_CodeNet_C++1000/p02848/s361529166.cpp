#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = acos(-1);

int main()
{
    char array[26] = {'A', 'B', 'C' , 'D' , 'E' , 'F' , 'G' ,
                      'H' , 'I' , 'J' , 'K' , 'L' , 'M' , 'N' ,
                      'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
                      'W', 'X', 'Y', 'Z'};
    int n;
    string s;
    cin >> n >> s;

    string ans;
    rep(i, s.size()) {
        rep(j, 26) {
            if (s[i] == array[j]) {
                if ((j + n) < 26) ans += array[j + n];
                else ans += array[j + n - 26];
            }
        }
    }
    cout << ans << endl;
    return 0;
}