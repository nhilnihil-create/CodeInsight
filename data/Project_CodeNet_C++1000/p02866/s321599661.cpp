#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <climits>
#include <map>
#include <set>
const int mod = 1e9 + 7;
const int inf = 1 << 20;
const long long INF = 1LL << 60;
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
using namespace std;

int d[101010];
int cnt[101010];

ll pow(int a, int n)
{
    if(n == 0){
        return 0;
    }else{
        ll k = 1;
        for(int i = 0; i < n; i++){
            k *= a;
            k %= 998244353;
        }
        return k;
    }


}

int main()
{
    int n;
    cin >> n;
    int m = 0;
    for(int i = 0; i < n; i++){
        cin >> d[i];
        m = max(d[i],m);
    }

    for(int i = 0; i < n; i++){
        cnt[d[i]]++;
    }

    ll ans = 1;

    if(cnt[0] != 1 || d[0] != 0){
        cout << 0 << endl;
        return 0;
    }else{
        for(int i = 0; i < m; i++){
            if(cnt[i] == 0){
                cout << 0 << endl;
                return 0;
            }
        }
        for(int i = 1; i <= m; i++){
            ans *= (pow(cnt[i-1],cnt[i]));
            ans %= 998244353;
        }
    }
    cout << ans;
}
