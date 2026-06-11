#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, q;
    cin >> k >> q;
    vector<int> d(k);
    for(auto &x : d)
        cin >> x;
    while(q--){
        int n, x, m;
        cin >> n >> x >> m;
        --n;
        ll s=0, ss=0;
        for(int i=0;i<k;i++){
            ll tmp = d[i]%m;
            if(!tmp)
                tmp = m;
            s+=tmp;
            if(i<n%k)
                ss+=tmp;
        }
        ll xx = x+s*(n/k)+ss;
        cout << n-(xx/m-x/m) << endl;
    }
    return 0;
}
