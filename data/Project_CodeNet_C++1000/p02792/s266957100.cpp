#include <bits/stdc++.h>

using namespace std;
#define int long long
#define mp make_pair
#define pb push_back


const int inf = 1e18;
const double EPS = 0.00000001;

signed main(){
    int n;
    cin >> n;
    int xx = 0;
    int nn = n;
    while(nn){
        xx++;
        nn /= 10;
    }
    int cnt = 0;
    vector<vector<int> > v(11,vector<int>(11));
    for(int i = 1;i<=n;i++){
        int a = i%10;
        int n1 = i;
        while(n1 > 9) n1 /= 10;
        int b = n1;
        v[a][b]++;
        cnt += v[b][a];
        v[a][b]++;
    }
    cout << cnt;
}
