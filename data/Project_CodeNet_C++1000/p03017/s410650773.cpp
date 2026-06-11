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
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

bool check(string s,int x,int y){
    for(int i=x; i<y; i++){
        if(s[i] == '#' && s[i+1] == '#')return true;
    }
    return false;
}

int main()
{
    int N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    A--;
    B--;
    C--;
    D--;
    string S;
    cin >> S;
    if(check(S,A,C) || check(S,B,D)){
        cout << "No" << endl;
        return 0;
    }
    bool flag = false;
    if(C > D){
        for(int i=B; i<=D; i++){
            if(S[i-1] == '.' && S[i] == '.' && S[i+1] == '.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}