#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

int M;
ll dsum, csum;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M;
    for(int i = 0; i < M; i++){
        ll d, c;
        cin >> d >> c;
        dsum += d * c;
        csum += c;
    }
    dsum--, csum--;
    cout << (dsum / 9) + csum << endl;
    return 0;
}