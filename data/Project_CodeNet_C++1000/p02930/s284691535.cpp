#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
//#define cerr if(false) cerr
#define show(...) cerr << #__VA_ARGS__ << " = ", debug(__VA_ARGS__);
using namespace std;
using ll = long long;
using pii = pair<int,int>;
template<typename T, typename S>
ostream &operator<<(ostream &os, pair<T, S> a){
    os << '(' << a.first << ',' << a.second << ')';
    return os;
}
template<typename T>
ostream &operator<<(ostream &os, vector<T> v){
    for(auto x:v)os << x << ' ';
    return os;
}
void debug(){cerr << '\n';}
template<typename H, typename... T>
void debug(H a, T... b){
    cerr << a;
    if(sizeof...(b))cerr << ", ";
    debug(b...);
}
int a[505][505];
void solve(int l, int r,int k){
    if(r - l <= 1)return;
    int mid = (l + r) / 2;
    solve(l,mid,k+1);
    solve(mid,r,k+1);
    for(int i = l; i < mid; i++){
        for(int j = mid; j < r; j++){
            a[i][j] = a[j][i] = k;
        }
    }

}
int main(){
    int n;
    cin >> n;
    solve(0,n,1);
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}