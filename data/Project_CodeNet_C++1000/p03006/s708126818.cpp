#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <stack>
#include <climits>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const ll mod = 1000000007;
const int inf = 1e9;
const long long INF = 1LL << 60;

int main()
{
    int n;
    cin >> n;
    ll x[n],y[n];
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    if(n == 1){
        cout << 1 << endl;
    }else{
        int ans = n+1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                ll p = x[j] - x[i];
                ll q = y[j] - y[i];

                int tmp = 0;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        if(k == l) continue;
                        if((p == x[l] - x[k]) && (q == y[l] - y[k])) tmp++;
                    }
                }
                ans = min(ans,n-tmp);
            }
        }
        cout << ans << endl;
    }
}