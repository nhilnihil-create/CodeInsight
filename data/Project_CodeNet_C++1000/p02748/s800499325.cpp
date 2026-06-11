#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i,s,n) for(int i = (s); i < (n); i++)
#define INF 1001001
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(){
    int A, B, m;
    cin >> A >> B >> m;
    int a[A], b[B];
    int min_a = INF, min_b = INF;
    rep(i, A) { 
        cin >> a[i];
        if(a[i]<min_a)
            min_a = a[i];
    }
    rep(i, B) { 
        cin >> b[i];
        if(b[i]<min_b)
            min_b = b[i];
    }
    int min_cost = min_a + min_b;
    rep(i, m) { 
        int x, y, c;
        cin >> x >> y >> c;
        min_cost = min(min_cost, a[x - 1] + b[y - 1] - c);
    }
    cout << min_cost << endl;
    return 0;
}