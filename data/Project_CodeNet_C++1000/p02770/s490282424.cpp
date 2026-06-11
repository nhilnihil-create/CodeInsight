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

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;


int main(){
    ll k, q;
    cin >> k >> q;

    ll d[5010];
    for(int i = 0; i < k; i++){
        cin >> d[i];
    }

    for(int i = 0; i < q; i++){
        ll n, x, m;
        cin >> n >> x >> m;
        ll e[5010];
        x %= m;
        ll s = 0;
        ll countZero = 0;
        for(int j = 0; j < k; j++){
            e[j] = d[j] % m;
            s += e[j];
            if(e[j] == 0){
                countZero++;
            }
        }
        x += s * ((n-1) / k);
        countZero *= ((n-1) / k);
        for(int j = 0; j < (n-1) % k; j++){
            x += e[j];
            if(e[j] == 0){
                countZero++;
            }
        }

        cout << n - 1 - x / m - countZero << endl;
    }

    return 0;
}
