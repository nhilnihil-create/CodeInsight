#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (n); i++)

typedef long long ll;

int main(void)
{
    int N,M,a,b;
    cin >> N >> M;
    dsu d(N);

    rep(i,M){
        cin >> a >> b;
        --a;
        --b;
        d.merge(a,b);
    }

    cout << d.groups().size()-1 <<endl;
     

    return 0;
}