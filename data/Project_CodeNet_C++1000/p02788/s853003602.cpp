#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, d;
    long long a;
    cin >> n >> d >> a;
    vector<pair<int, long long> >v;
    for(int i = 0; i < n; i++){
        int p, q;
        cin >> p >> q;
        v.push_back({p, q});
    }
    sort(v.begin(), v.end());
    vector<int>bomb;
    vector<long long>val, pref;
    bomb.push_back(-2000000000);
    val.push_back(0);
    pref.push_back(0);
    for(int i = 0; i < n; i++){
        int p = lower_bound(bomb.begin(), bomb.end(), v[i].first - 2 * d) - bomb.begin();
        long long x;
        if(p == bomb.size()){
            x = v[i].second;
        }
        else{
            long long r = pref.back() - pref[p] + val[p];
            x = v[i].second - r * a;
        }
        if(x > 0){
            long long cnt = x/a + (x % a != 0);
            bomb.push_back(v[i].first);
            val.push_back(cnt);
            long long k = pref.back() + cnt;
            pref.push_back(k);
        }
    }
    cout << pref.back();
    return 0;
}