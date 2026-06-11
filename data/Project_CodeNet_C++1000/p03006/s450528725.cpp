#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    int n;
    cin >> n;

    P x[n];
    for(int i = 0; i < n; i++){
        cin >> x[i].first >> x[i].second;
    }

    sort(x, x + n);

    map<P, int> m;
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            P t = make_pair(x[j].first - x[i].first, x[j].second - x[i].second);
            auto itr = m.find(t);
            if(itr == m.end()){
                m[t] = 1;
            }else{
                m[t]++;
            }
        }
    }

    int k = 0;

    for(auto i = m.begin(); i != m.end(); ++i){
        if(k < i->second){
            k = i->second;
        }
    }

    int ans = 0;
    ans = n - k;

    cout << ans << endl;
}