#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < (n);i++)
ll INF = 1000000010; 
const ll MOD = 1000000007;


int main(){ 
    ll h, w; cin >> h >> w;
  	if(h == 1 || w == 1) cout << 1 << endl;
    else if((h * w) % 2 == 0) cout << h * w / 2 << endl;
    else cout << h * w / 2 + 1 << endl;
} 