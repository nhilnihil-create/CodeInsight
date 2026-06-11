#include <iostream>
#include <vector>
#include <cmath>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

using namespace std;
typedef long long ll;

int main()
{
    int n, k, q; cin >> n >> k >> q;
    vector <ll> A(q);
    for (int i = 0; i < q; i ++){
        cin >> A.at(i);
    }
    vector <ll> ans(n, k);
    
    for (auto a: A){
        ans.at(a - 1) += 1;
    }

    for (auto p: ans){
        p -= q;
        if (p < 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}