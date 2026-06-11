#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <stack>
#include <complex>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
#include <cfloat>
#include <math.h>
#include <numeric>
#include <string.h>
#include <sys/time.h>
#include <random>


#define fs first
#define sc second
#define endl "\n"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef pair<ll, ll> P;


int main(){
    int n, m;   cin >> n >> m;
    priority_queue<ll> q;
    for(int i = 0; i < n; i++){
        int a;  cin >> a;
        q.push(a);
    }

    for(int i = 0; i < m; i++){
        int x = q.top();    q.pop();
        x = x / 2;
        q.push(x);
    }

    ll res = 0;
    while(!q.empty()){
        res += q.top();
        q.pop();
    }

    cout << res << endl;


    return 0;
}
