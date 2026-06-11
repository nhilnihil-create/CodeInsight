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

int N;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            for(int k = 0; k < 30; k ++){
                if(((i >> k) & 1) ^ ((j >> k) & 1)){
                    cout << k + 1 << " ";
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}