/*
          ,     \    /      ,
         / \    )\__/(     / \
        /   \  (_\  /_)   /   \
   ____/_____\__\@  @/___/_____\____
  |             |\../|              |
  |              \VV/               |
  |        ------hoi-------         |
  |_________________________________|
   |    /\ /      \\       \ /\    |
   |  /   V        ))       V   \  |
   |/     `       //        '     \|
   `              V                '
*/

#include <bits/stdc++.h>

#define ld long double
#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
#define f first
#define se second
#define Speedforce boost();
#define fop(s1, s2) freopen(s1, "r", stdin);freopen(s2, "w", stdout);

using namespace std;

void boost(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

const int N = 1e6;
const ll inf = 1e9 + 9;
const ld PI = acos(-1);

ll bin_pow(ll x, ll y){
    ll res = 1, base = x;
    while(y){
        if(y & 1){
            res *= base;
            res %= inf;
        }
        base *= base;
        base %= inf;
        y /= 2;
    }
    return res;
}

int n;
int a[1005][1005];
int used[1005];
int pos[1005];

int main(){
    Speedforce
    //fop("", "")
    cin >> n;
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j < n;j ++){
            cin >> a[i][j];
        }
        pos[i] = 1;
    }
    int cnt = 0;
    while(1){
        cnt++;
        bool flag1 = 1, flag2 = 1;
        for(int i = 1;i <= n;i ++){
            if(pos[i] >= n){
                continue;
            }
            int c = a[i][pos[i]];
            if(i == a[c][pos[c]]){
                flag2 = 0;
                pos[i]++;
                pos[c]++;
                int mx = max(used[i], used[c]);
                used[i] = mx + 1;
                used[c] = mx + 1;
                i = 0;
            }
        }
        for(int i = 1;i <= n;i ++){
            //cout << pos[i] << " ";
            if(pos[i] < n){
                flag1 = 0;
            }
            cnt = max(cnt, used[i]);
        }
        //cout << endl;
        if(flag1){
            cout << cnt;
            return 0;
        }
        if(flag2){
            cout << -1;
            return 0;
        }
    }
}
