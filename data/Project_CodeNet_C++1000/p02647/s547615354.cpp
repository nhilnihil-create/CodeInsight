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

int N, K;
int A[50][200010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    for(int i = 1; i <= N; i++){
        cin >> A[0][i];
    }

    K = min(K, 49);
    for(int i = 1; i <= K; i++){
        for(int j = 1; j <= N; j++){
            A[i][max(1, j - A[i - 1][j])]++;
            A[i][min(j + A[i - 1][j] + 1, N + 1)]--;
        }

        for(int j = 1; j <= N; j++){
            A[i][j + 1] += A[i][j];
        }
    }

    for(int i = 1; i <= N; i++){
        cout << A[K][i];
        if(i != N) cout << " ";
        else cout << endl;
    }
    return 0;
}
