#define DEBUG 0

#include <bits/stdc++.h>
using namespace std;

#if DEBUG
// basic debugging macros
int __i__,__j__;
#define printLine(l) for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl
#define printLine2(l,c) for(__i__=0;__i__<l;__i__++){cout<<c;}cout<<endl
#define printVar(n) cout<<#n<<": "<<n<<endl
#define printArr(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<endl
#define print2dArr(a,r,c) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<endl;}
#define print2dArr2(a,r,c,l) cout<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<setw(l)<<setfill(' ')<<a[__i__][__j__]<<" ";}cout<<endl;}

// advanced debugging class
// debug 1,2,'A',"test";
class _Debug {
    public:
        template<typename T>
        _Debug& operator,(T val) {
            cout << val << endl;
            return *this;
        }
};
#define debug _Debug(),
#else
#define printLine(l)
#define printLine2(l,c)
#define printVar(n)
#define printArr(a,l)
#define print2dArr(a,r,c)
#define print2dArr2(a,r,c,l)
#define debug
#endif

// define
#define MAX_VAL 999999999
#define MAX_VAL_2 999999999999999999LL
#define EPS 1e-6
#define mp make_pair
#define pb push_back

// typedef
typedef unsigned int UI;
typedef long long int LLI;
typedef unsigned long long int ULLI;
typedef unsigned short int US;
typedef pair<int,int> pii;
typedef pair<LLI,LLI> plli;
typedef vector<int> vi;
typedef vector<LLI> vlli;
typedef vector<pii> vpii;
typedef vector<plli> vplli;

// ---------- END OF TEMPLATE ----------

string S;
int dp[200000][5];
int check(int a,int la,int b,int lb) {
    if (la != lb) return 1;
    int i;
    for (i = 0; i < la; i++) {
        if (S[a+i] != S[b+i]) return 1;
    }
    return 0;
}
int main() {
    cin >> S;

    int i,j,k,ans = 0;
    for (i = 0; i < S.size(); i++) {
        for (j = 0; j < 5; j++) dp[i][j] = -1e9;
        for (j = 1; j < 5; j++) {
            if (j > i+1) break;
            else if (j == i+1) dp[i][j] = max(dp[i][j],1);
            else {
                for (k = 1; k < 5; k++) {
                    if (dp[i-j][k] == -1e9) continue;
                    if (!check(i-j-k+1,k,i-j+1,j)) continue;
                    dp[i][j] = max(dp[i][j],dp[i-j][k]+1);
                }
            }
            ans = max(ans,dp[i][j]);
        }
        printArr(dp[i],5);
    }
    printf("%d\n",ans);

    return 0;
}

