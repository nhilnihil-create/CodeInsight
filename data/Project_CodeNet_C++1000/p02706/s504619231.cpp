#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i=0; i<n; i++)
#define REPA(i, a, n) for(int i=a; i<n; i++)
#define REPE(i, a, n) for(int i=a; i<=n; i++)
#define SetArray(a, n) for(int array_i=0; array_i<n; array_i++) cin >> a[array_i]
#define print(x) cout << x
#define printw(x) cout << x << " "
#define println(x) cout << x << endl
#define printl() cout << endl
#define sqr(x) (x)*(x)
#define cube(x) (x)*(x)*(x)
typedef long long ll;
typedef unsigned int uint;
typedef vector<int> vi;

int main(){
    int n, m;
    cin >> n >> m;

    int a;
    ll total = 0;
    REP(i, m){
        cin >> a;
        total += a;
    }

    if(total > n)
        println(-1);
    else
        println(n-total);

    return 0;
}


