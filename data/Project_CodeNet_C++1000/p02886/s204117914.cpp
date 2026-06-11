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
    int n;
    cin >> n;

    vector<int> d;
    REP(i,n){
        ll tmp;
        cin >> tmp;
        d.push_back(tmp);
    }

    ll sum = 0;
    REP(i,n){
        FOR(j,i+1,n){
            if(i==j) continue;
            else{
                sum += d[i]*d[j];
            }
        }
    }
    cout << sum << endl;
    return 0;
}