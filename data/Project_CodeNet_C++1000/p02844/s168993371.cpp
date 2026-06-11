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
    string s;
    cin >> N >> s;
    int ans=0;
    REP(i,10){
        REP(j,10){
            REP(k,10){
                int idx = 0;
                REP(n,N){
                    if(0 == idx && i == (s[n]-'0')){
                        idx++;
                        continue;
                    }
                    if(1 == idx && j == (s[n]-'0')){
                        idx++;
                        continue;
                    }
                    if(2 == idx && k == (s[n]-'0')){
                        idx++;
                        continue;
                    }
                }
                if(3 == idx){
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
}