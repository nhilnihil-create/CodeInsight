#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}


signed main() {
    int N, A, B, C, D;
    string S;
    cin >> N >> A >> B >> C >> D >> S;

    bool acan=true, bcan=true;
    FOR(i, A, C-2) {
        if(S[i]=='#' && S[i+1]=='#') acan=false;
    }
    FOR(i, B, D-2) {
        if(S[i]=='#' && S[i+1]=='#') bcan=false;
    }

    if(!acan || !bcan) {
        cout << "No" << endl;
        return 0;
    }

    if(C<D) {
        cout << "Yes" << endl;
    } else {
        bool can = false;
        FOR(i, B-2, D-1) {
            if(S[i]=='.'&&S[i+1]=='.'&&S[i+2]=='.') {
                can = true;
                break;
            }
        }
        if(can)  cout << "Yes" << endl;
        else cout << "No" << endl;
    }


    return 0;
}