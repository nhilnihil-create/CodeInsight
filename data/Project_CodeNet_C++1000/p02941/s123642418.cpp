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
int A[200010];
int B[200010];
bool flag = true;
ll ans = 0;

queue<int> mx;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++){
        int l = (i - 1 + N) % N;
        int r = (i + 1) % N;
        if(B[i] >= B[l] + B[r]) mx.push(i);
    }
    while(!mx.empty()){
        int id = mx.front();
        mx.pop();
        int l = (id - 1 + N) % N;
        int r = (id + 1) % N;
        ans += B[id] / (B[l] + B[r]);
        B[id] %= B[l] + B[r];
        if(B[id] < A[id]){
            if((A[id] - B[id]) % (B[l] + B[r]) != 0){
                cout << -1 << endl;
                return 0;
            }
            ans -= (A[id] - B[id]) / (B[l] + B[r]);
            B[id] = A[id];
        }
        int r2 = (r + 1) % N;
        int l2 = (l - 1 + N) % N;
        if(B[r] > B[id] + B[r2] && B[r] != A[r]) mx.push(r);
        if(B[l] > B[id] + B[l2] && B[l] != A[l]) mx.push(l);
    }
    for(int i = 0; i < N; i++) if(A[i] != B[i]) flag = false;
    cout << (flag ? ans : -1) << endl;
    return 0;
}