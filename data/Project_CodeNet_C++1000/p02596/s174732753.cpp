#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long long ld;


#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define mp make_pair
#define pb push_back
#define lp(i,s,f) for(ll i = s; i < ll(f); i++)
#define inF freopen("input.in", "r", stdin);
#define outF freopen("output.in", "w", stdout);
#define endl '\n'
#define MOD 1000000007
#define mm(arr) memset(arr, 0, sizeof(arr))

int main(){
    FAST
    string s = "";
    int n; cin >> n;
    for(int i = 0; i < 2e6; i++){
        s += '7';
    }
    int res = 0;
    int cnt = 0;
    for(int i = 0; i < 2e6; i++){
        res = (res*10 + (int)s[i] - '0')%n;
        cnt++;
        if(res == 0)break;
    }
    if(cnt == 2e6)cnt = -1;
    cout << cnt;
    return 0;
}
