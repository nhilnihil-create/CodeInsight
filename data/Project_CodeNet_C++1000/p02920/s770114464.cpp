#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

int niz[1000005];
vector <int> vec;
multiset <int> treba;

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    n = (1<<n);
    for(int i=1; i<=n; i++) cin >> niz[i];
    sort(niz+1, niz+1+n);
    reverse(niz+1, niz+1+n);
    vec.push_back(niz[1]);
    for(int i=2; i<=n; i++){
        treba.insert(-niz[i]);
    }
    vector <int> nvec;
    for(int j=1; (1<<j)<=n; j++){
        nvec.clear();
        for(auto c : vec){
            auto x = treba.upper_bound(-c);
            if(x == treba.end()){
                cout << "No\n";
                return 0;
            }
            nvec.push_back(-(*x));
            treba.erase(x);
        }
        for(auto c : nvec) vec.push_back(c);
    }
    cout << "Yes\n";
    return 0;
}
