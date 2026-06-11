#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
using ll = long long int;

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++)cin >> p[i];

    vector<int> index(n+1);
    for(int i = 0; i < n; i++){
        index[p[i]] = i;
    }

    ll ans = 0;
    set<int> Lind;
    Lind.insert(index[n]);
    Lind.insert(-1); Lind.insert(n);
    for(int i = n-1; i > 0; i--){
        int nowind = index[i];
        set<int>::iterator it = Lind.upper_bound(nowind);
        int rmin = *it;
        --it;
        int lmax = *it;
        ++it;
        if (rmin != n){
            ++it;
            int rmax = *it;
            --it;
            ans += (ll)i * (rmax - rmin) * (nowind - lmax);
        }
        if (lmax != -1){
            --it;
            --it;
            int lmin = *it;
            ans += (ll)i * (lmax - lmin) * (rmin - nowind);
        }

        Lind.insert(nowind);
    }
    cout << ans << endl;
    return 0;
}