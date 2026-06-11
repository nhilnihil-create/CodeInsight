#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1010000000000000017LL;
const ll MOD = 1000000007LL;

#define REP(i, n) for(ll i = 0 ; i < n; i++)

//#define DEBUG(fmt, ...)
#define DEBUG(fmt, ...) fprintf(stderr, fmt "\n", ##__VA_ARGS__)

int main(){
    std::cout<<std::fixed<<std::setprecision(10);

    ll N;
    cin >> N;

    vector<pair<ll,ll>> jobs;

    REP(i,N){
        ll A, B;
        cin >> A >> B;
        jobs.push_back(make_pair(B,A));
    }
    sort(jobs.begin(), jobs.end());


    ll cur = 0;
    REP(i,N){
       cur += jobs[i].second;
       if( jobs[i].first < cur ){
         cout << "No" << endl;
         return 0;
       }

    }
    cout << "Yes" << endl;
}
