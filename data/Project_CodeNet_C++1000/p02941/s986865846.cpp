#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <bitset>
#include <cmath>
#define ff first
#define ss second
#define MAXN 300005
#define INF 1000000001000000001LL
#define int long long

using namespace std;

const int mod = 998244353; //1000000007;
int n, i, ans, a[MAXN], b[MAXN];
set <pair<int, int> > s;

main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base :: sync_with_stdio(false);
    cin.tie();
    cin >> n;

    for(i = 0; i < n; i++)
        cin >> a[i];

    for(i = 0; i < n; i++){
        cin >> b[i];

        s.insert({b[i], i});
    }

    while(s.size() != 0){
        int i = (--s.end()) -> ss;
        s.erase(--s.end());
        int x = b[(i + 1) % n], y = b[(i + n - 1) % n];

        if(b[i] == a[i])
            continue;
        
        if(b[i] <= x + y){
            cout << "-1";
            return 0;
        }

        if(a[i] >= x + y){
            if((b[i] - a[i]) % (x + y)){
                cout << "-1";
                return 0;
            }

            ans += (b[i] - a[i]) / (x + y);
            b[i] = a[i];
        }
        else{
            int cnt = (b[i] - 1) / (x + y);
            ans += cnt;
            b[i] -= cnt * (x + y);

            if(b[i] != a[i])
                s.insert({b[i], i});
        }
    }

    cout << ans;
    return 0;
}





