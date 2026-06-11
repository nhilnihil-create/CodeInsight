#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n); i++) 
#define dunk(n) cout << n << endl
#define all(a) (a).begin(),(a).end()
typedef pair<int,int> P;
typedef long long ll;

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int d = a+b+c;
    if(d >= 22) dunk("bust");
    else dunk("win");
    return 0;
}