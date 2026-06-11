#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    ll N;
    cin >> N;
    ll A,B;
    cin >> A >> B;
    //
    ll num_Blue_set = N / (A+B);
    ll ans;
    ans = num_Blue_set * A;
    ll num = N % (A + B);
    if(num > 0){
        if(num <= A){
            ans = ans + num;
        }
        else{
            ans = ans + A;
        }
    }
    cout << ans << endl;
}