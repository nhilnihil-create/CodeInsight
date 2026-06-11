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
    string s;
    int q;
    cin >> s;
    cin >> q;
    int cnt1 = 0;

    string sf = "";
    string sb = "";
    REP(i,q){
        int t;
        cin >> t;
        if(1 == t){
            cnt1++;
        }else{
            int f;
            string c;
            cin >> f;
            cin >> c;

            if((0 == cnt1%2 && 1 == f) || (0 != cnt1%2 && 2 == f)){
                sf = c + sf;
            }else{
                sb = sb + c;
            }
        }
    }

    if(0 != cnt1%2){
        reverse(s.begin(),s.end());
        reverse(sf.begin(),sf.end());
        reverse(sb.begin(),sb.end());
        s = sb + s + sf;
    }else{
        s = sf + s + sb;
    }

    cout << s << endl;

}