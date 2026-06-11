#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

int n , ans;
int p[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    for(int i = 1; i < n - 1; i++){
        int x = min(p[i] , min(p[i - 1] , p[i + 1]));
        int y = max(p[i] , max(p[i - 1] , p[i + 1]));
        int z = (p[i - 1] + p[i] + p[i + 1]) - (x + y);
        if(z == p[i])   ans++;
    }
    cout << ans << endl;
    return 0;
}
