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
    double a,b,x;
    cout << fixed << setprecision(20);
    cin >> a >> b >> x;
    x /= a;
    double c = x / a;
    double h_sub = b - c;
    if(c >= h_sub){
        cout << atan(2*h_sub/a)*90*2/M_PI << endl;
    }else{
        double d = 2 * x / b;
        cout << atan(b/d)*90*2/M_PI << endl;
    }
}