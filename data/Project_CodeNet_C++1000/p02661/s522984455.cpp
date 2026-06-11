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
vector<ll> A;
vector<ll> B;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        if(N % 2 == 0) a *= 2, b *= 2;
        A.push_back(a);
        B.push_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int h = (N - 1) / 2;
    if(N % 2){
        cout << B[h] - A[h] + 1 << endl;
    }else{
        cout << (B[h] + B[h + 1]) / 2 - (A[h] + A[h + 1]) / 2 + 1 << endl; 
    }
    return 0;
}