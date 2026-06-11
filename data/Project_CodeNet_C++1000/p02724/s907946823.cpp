
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <stack>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
#define pi acos(-1.0)
#define MAX 1000010
//////////////////////////////////////////////////////////////////////////
/* Custom function starts here */

/* Custom function ends here: */
//////////////////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  /* MAIN Code STARTS here: */
    int coins, hap;
    int cnt1, cnt5;

    cin >> coins;
    cnt1 = coins/500;
    int rem = coins%500;
    cnt5 = rem/5;
    cout << (cnt1*1000) + (cnt5*5) << endl;

  /* MAIN Code ENDS here: */

}