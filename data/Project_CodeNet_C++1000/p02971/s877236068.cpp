#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=b;i--)
#define ALL(x) x.begin(),x.end()
#define SIZE(x) ll(x.size())

#define INF 1000000000000 //10^12
#define MOD 1000000007 //10^9+7:合同式の法
 
int main(){
    ll n;
    cin >> n;

    vector<ll> a,a_;
    REP(i,n){
        ll tmp;
        cin >> tmp;
        a.push_back(tmp);
        a_.push_back(tmp);
    }
    
    sort(ALL(a));

    REP(i,n){
        if(a_[i]==a[n-1]){
            cout << a[n-2] << endl;
        }
        else{
            cout << a[n-1] << endl;
        }
    }
    
    return 0;
}