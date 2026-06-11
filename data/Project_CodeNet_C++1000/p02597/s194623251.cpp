#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cstring>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
#define rep(i, n) for(long long i=0; i<n; i++)
#define reps(i, s, e) for(long long i=s; i<e; i++)
#define repr(i, n) for(long long i=n-1; i>=0; i--)
#define reprs(i, s, e) for(long long i=e-1; i>=s; i--)

int main(){

    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n; cin >> n;
    string c; cin >> c;

    ll left = n - 1;
    rep(i, n){
        if(c[i] == 'W'){
            left = i;
            break;
        }
    }

    ll right = 0;
    repr(i, n){
        if(c[i] == 'R'){
            right = i;
            break;
        }
    }

    ll cnt = 0;
    bool is_finished = false;
    while(left < right){
        cnt++;
        c[left] = 'R';
        c[right] = 'W';
        
        while(c[left] == 'R'){
            left++;
            if(left == n){
                is_finished = true;
            }
        }

        while(c[right] == 'W'){
            right--;
            if(right < 0){
                is_finished = true;
            }
        }

        if(is_finished){
            break;
        }
    }

    cout << cnt << endl;

    return 0;
}