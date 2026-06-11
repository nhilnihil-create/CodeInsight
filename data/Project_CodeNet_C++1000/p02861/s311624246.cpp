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
    vector<int> idx;
    REP(i,N)idx.pb(i);
    vector<pair<double,double>> pos;
    REP(i,N){
        double x,y;
        cin >> x >> y;
        pos.pb({x,y});
    }
    double dis=0.0;
    int cnt=0;
    do{
        REP(i,idx.size()-1){
            int id = idx[i];
            int idn = idx[i+1];
            dis += sqrt(pow((pos[id].first-pos[idn].first),2) + pow((pos[id].second-pos[idn].second),2));
        }
        cnt++;
    }while(next_permutation(idx.begin(),idx.end()));
    cout << fixed << setprecision(10) << (dis/cnt) << endl;
}