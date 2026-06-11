#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll inf = 1000000007;
char tehuda[100005];
int main(void) {
    ll n, k;
    cin >> n >> k;
    ll r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    ll sum = 0;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == 'r') {
            tehuda[i] = 'p';
        }
        else if (t[i] == 's') {
            tehuda[i] = 'r';
        }
        else {
            tehuda[i] = 's';
        }
    }
  
    for (int i = 0; i < t.size(); i++) {
        if (i > k - 1) {
            if (tehuda[i - k] != tehuda[i]) {
                if (t[i] == 'r') {
                    sum+=p;
                }
                else if (t[i] == 's') {
                    sum += r;
                }
                else {
                    sum += s;
                }
            }
            else {
                tehuda[i] = 'd';
                continue;
            }
        }
        else {
            if (t[i] == 'r') {
                sum += p;
            }
            else if (t[i] == 's') {
                sum += r;
            }
            else {
                sum += s;
            }
        }
        
    }
    cout << sum << endl;
    return 0;
}


