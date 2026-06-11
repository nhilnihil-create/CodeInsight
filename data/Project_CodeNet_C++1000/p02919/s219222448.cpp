#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define LLINF 9223372036854775807
#define MOD ll(1e9+7)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr<<#x<<": "<<x<<endl

int main(){
    int n;
    cin >> n;
    vector<int> p(n);
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        cin >> p[i];
        mp[p[i]] = i;
    }

    set<int> st;
    st.insert(mp[n]);
    ll ans = 0;
    for(int i = n-1; i > 0; i--){
        auto itr = st.insert(mp[i]);
        auto itr_org = itr;
        int l1, l2, r1, r2;
        if(itr.first == st.begin()){
            l2 = -1; l1 = -1;
        }else if(--itr.first == st.begin()){
            l2 = -1; l1 = *itr.first;
        }else{
            l1 = *itr.first;
            l2 = *(--itr.first);
        }

        itr = itr_org;
        if(itr.first == --st.end()){
            r1 = n; r2 = n;
        }else if(++itr.first == --st.end()){
            r1 = *itr.first; r2 = n;
        }else{
            r1 = *itr.first;
            r2 = *(++itr.first);
        }
        ans += ll(i)*(l1-l2)*(r1-mp[i]);
        ans += ll(i)*(r2-r1)*(mp[i]-l1);

    }


    cout << ans << endl;
    return 0;

}
