#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <iterator>
using namespace std;


int main(){
    long long n, k, ans = 0;
    cin >> n >> k;
    vector<long long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<long long> p(n + 1);
    for(int i = 0; i < n; ++i)
        p[i + 1] = (p[i] + a[i] - 1) % k;
    map<long long, long long> m;
    for(int i = 0; i <= n; ++i) {
      if(i - k >= 0) m[p[i - k]]--;
      ans += m[p[i]];
      m[p[i]]++;
    }
    cout << ans;
}
