#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    ll right = 0,left = 0;
    vector<ll> a(n);
    REP(i,n){
        cin >> a[i];
        right += a[i];
    }

    ll answer = INT64_MAX;
    
    REP(i,n){
        left+=a[i];
        right-=a[i];
        answer = min(answer,llabs(left-right));
    }
    cout << answer << endl;
    
    return 0;
}