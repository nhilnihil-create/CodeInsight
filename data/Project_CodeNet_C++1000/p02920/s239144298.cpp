#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define pb push_back
#define mod 1000000007
#define mk make_pair
#define sz size


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll k,j;
    cin>>k;
    ll i,n,a;
    n=1<<k;
    vector<ll> v;
    multiset<ll> s;
    for(i=0;i<n;i++){
        cin>>a;
        s.insert(-1*a);
    }
    v.pb(*s.begin());
    s.erase(s.begin());
    for(i=0;i<k;i++){
        vector<ll> temp;
        for(j=0;j<v.sz();j++){
            auto it=s.upper_bound(v[j]);
            if(it==s.end()){
                cout<<"No"<<endl;
                return 0;
            }
            temp.pb(*it);
            s.erase(it);
        }
        for(j=0;j<temp.sz();j++)
            v.pb(temp[j]);
        sort(v.begin(),v.end());
    }
    cout<<"Yes"<<endl;
    return 0;  
}