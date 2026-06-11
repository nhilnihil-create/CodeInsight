#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int main(){
    int n,k;
    cin >> n >> k;
    vint p(n);
    cin >> p;
    int max = 0;
    int idx = 0;
    for(int i=0; i<k;i++){
        max += p[i];
    }
    int tmp = max;
    for(int i=k; i<n;i++){
        tmp += p[i];
        tmp -= p[i-k];
        if(max < tmp){
            max = tmp;
            idx = i-k+1;
        }
    }
    double ans = 0;
    for(int i=idx;i<(idx+k);i++){
        ans += (p[i]+1)/((double)2);
    }
    cout << fixed << setprecision(10) <<ans << endl;

}