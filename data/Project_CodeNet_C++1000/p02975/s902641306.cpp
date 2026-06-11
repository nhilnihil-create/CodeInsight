#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define All(V) V.begin(), V.end()
typedef long long int ll;
typedef pair<int, int> P;
const ll MOD = 1e9+7, INF = 1e9;

int main()
{
    int n; cin >> n;
    vector<ll> v(n);
    map<ll, int> m;
    rep(i, n){
        cin >> v[i];
        m[v[i]]++;
    }
    if(m.size() == 1){
        if(m[0] == n)cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    if(m.size() > 3){
        cout << "No" << endl;
        return 0;
    }
    if(m.size() == 2){
        if(m[0] == n / 3){
            cout << "Yes" << endl;
        }
        else cout << "No" << endl;
        return 0;
    }
    if(m.size() == 3){
        auto i = m.begin();
        ll k = i ->first; i++;
        while(i != m.end()){
            k ^= i->first;
            i++;
        }
        if(k != 0){
            cout << "No" << endl;
        }
        else{
            bool f = true;
            for(auto i = m.begin(); i != m.end(); i++){
                if(i->second != n/3){
                    f = false;
                }
            }
            if(f) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    
    system("pause");
}