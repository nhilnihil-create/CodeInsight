#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template < typename T > string tost( const T& n ) { ostringstream stm; stm << n; return stm.str();}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1001001001;

// 片方を無視したときにstartからgoalまで到達できるか
bool isOK (int start, int goal,string &S) {
    int cur = 0;
    for(int i = start; i <= goal; ++i) {
        if(S[i] == '.') cur = 0;
        else cur++;
        if(cur == 2) return false;// "##"があるとき到達できない
    }
    return true;
}
// startからgoalまでに飛び越せる場所つまり"..."があるか
bool swapOK (int start, int goal,string &S) {
    for(int i = start; i <= goal; ++i) {
        if(S[i] == '.' && S[i-1] == '.' && S[i+1] == '.') return true;
    }
    return false;
}

int main()
{
cin.tie(0);
ios::sync_with_stdio(false);

int N,A,B,C,D;
cin >> N >> A >> B >> C >> D;
A--;B--;C--;D--;
string S;
cin >> S;

if(C < D) {
    if(isOK(A, C, S) && isOK(B, D, S)) cout << "Yes" << endl;
    else cout << "No" << endl;
}
else {
    if(isOK(A, C, S) && isOK(B, D, S) && swapOK(B, D, S)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

return 0;
}