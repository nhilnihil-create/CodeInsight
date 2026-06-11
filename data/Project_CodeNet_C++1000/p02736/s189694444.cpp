#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<int,int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<typename T> T gcd(T a,T b){return b?gcd(b,a%b):a;}
const LL mod=998244353;
const LL LINF=1LL<<62;
const int INF=1<<30;
int dx[]={1,0,-1,0,1,-1,1,-1};
int dy[]={0,1,0,-1,1,-1,-1,1};

vector<int> a;

int C(int n,int r){
    return (n & r) == r;
}

int f(int n){
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret = ret ^ (C(n - 1, i) * a[i]);
    }
    return ret;
}


int main(){
    int n;cin >> n;
    string s;cin >> s;
    a.resize(n-1);
    int c2 = 0, c1 = 0, c0 = 0;
    for (int i = 0; i < n-1; i++) {
        a[i] = abs(s[i+1] - s[i]);
        if(a[i] == 2) c2++;
        else if(a[i] == 1) c1++;
        else c0++;
    }
    if(c1 == 0){
        for (int i = 0; i < n-1; i++) {
            a[i] /= 2;
        }
        cout << (f(n-1)?2:0) << endl;
    }
    else{
        for (int i = 0; i < n-1; i++) {
            a[i] %= 2;
        }
        cout << f(n-1) << endl;
    }
    return 0;
}
