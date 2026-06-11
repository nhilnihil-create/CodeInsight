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
int main()
{
    int N;
    cin >> N;
    vll H(N);
    cin >> H;
    vint cnt(N,0);
    REP(i,N-1){
        if(H[i] >= H[i+1]){
            cnt[i+1] = cnt[i]+1;
        }
    }
    sort(cnt.begin(),cnt.end());
    cout << cnt[N-1] << endl;
}