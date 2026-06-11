#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<algorithm>
#include <numeric>
#include<map>
#include<unordered_map>
#include <queue>
 
using namespace std;
using ll=long long;
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> neg, pos;
    rep(i, n){
        cin >> a[i];
        if(a[i] < 0)neg.push_back(a[i]);
        else pos.push_back(a[i]);
    }
    sort(ALL(a));

    ll ans = a.back()-a.front();
    for(ll i=1; i < n-1; ++i)ans += abs(a[i]);
    cout << ans << endl;
    
    if(n == 2){
        cout << a.back() << " " << a.front();
        return 0;
    }
    
    if(neg.empty()){
        cout << a.front() << " " << a.back() << endl;
        a.front() -= a.back();
        a.pop_back();
        while(a.size() > 2){
            cout << a.front() << " " << a.back() << endl;
            a.front()-=a.back();
            a.pop_back();
        }
        cout << a.back() << " " << a.front();
    }
    else if(pos.empty()){
        cout << a.back() << " " << a.front() << endl;
        a.back() -= a.front();
        a.erase(a.begin());
        while(a.size() > 2){
            cout << a.back() << " " << a.front() << endl;
            a.back()-=a.front();
            a.erase(a.begin());
        }
        cout << a.back() << " " << a.front();
    }
    else {
        ll ps = pos.back();
        pos.pop_back();
        ll ng = neg.back();
        neg.pop_back();
        while(!pos.empty()){
            cout << ng << " " << pos.back() << endl;
            ng -= pos.back();
            pos.pop_back();
        }
        while(!neg.empty()){
            cout << ps << " " << neg.back() << endl;
            ps -= neg.back();
            neg.pop_back();
        }
        cout << ps << " " << ng << endl;
    }
}