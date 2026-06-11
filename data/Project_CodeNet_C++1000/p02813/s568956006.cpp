#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef pair<int, int> pii;
int main(){
    int n; cin >> n;
    vector<int> p(n), q(n);
    vector<int> v(n);
    rep(i, n) cin >> p.at(i);
    rep(i, n) cin >> q.at(i);
    rep(i, n) v.at(i) = i+1;
    int a, b, count = 1;
    do{
        if(v == p) a = count;
        if(v == q) b = count;
        count++;
    }while(next_permutation(v.begin(), v.end()));
    cout << abs(a - b) << endl;
    return 0;
}
