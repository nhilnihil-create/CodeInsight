#include<bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define ll long long
#define pii pair<int,int>


void test_case()
{
    ll n,k;
    cin >> n >> k;
    ll a[n+1],index=-1;
    for(ll i=1; i<=n; i++) cin>>a[i];
    ll i=1;
    set<ll> st;
    vector<ll> vec={1};

    st.insert(1);
    for(ll m=0;m<k;m++) {
        i=a[i];
        if(st.find(i)==st.end()) {
            st.insert(i);
            vec.pb(i);
        } else {
            for(ll j=0;j<(ll)vec.size();j++) {
                if(vec[j]==i) {
                    index=j;
                    break;
                }
            }
            break;
        }
    }
    if(index==-1) {
        cout<<i;
        return;
    }
    ll offset=index, looplen = vec.size() - index;

    cout<<vec[index + (k-offset)%looplen];
}

int main()
{
    fastio
//    int t;
//    cin>>t;
//    while(t--)
    test_case();
}
