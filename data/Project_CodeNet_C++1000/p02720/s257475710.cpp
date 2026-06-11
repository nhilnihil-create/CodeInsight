#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rep_ll(i,n) for(ll i = 0; i < (ll)(n); i++)
using namespace std;
typedef long long ll;
typedef unsigned long long u_ll;
typedef pair<int, int> pair_;
const long double PI = (acos(-1));
const int INF = 1001001001;
const int dx[] = {-1, 0, 1, 0}; const int dy[] = {0, -1, 0, 1};
ll mod = 1000000007;
int main(){
    int k;
    cin >> k;
    vector<ll> a;
    int keta = 1;
    for(int i=1; i<10; i++) a.push_back(i);
    while(1){
        if(k<=a.size()){
            cout << a[k-1];    
            return 0;//プログラム終了
        }
        k-=a.size();
        vector<ll> old;
        swap(a, old);//oldとaを入れ替え, aが空, oldが桁毎の値になる
        for(ll x: old){//toproop
            for(int j=-1; j<=1; j++){
                int d = x%10 + j;
                if(d<0||d>9) continue;
                ll num = x*10 + d;
                a.push_back(num);
            }
        }
    }
}