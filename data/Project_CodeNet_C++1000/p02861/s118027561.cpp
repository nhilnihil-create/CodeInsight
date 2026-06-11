#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>
#include <utility>
#include <sstream>

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) x.begin(),x.end()
#define chmax(x,y) (x = max(x,y))
#define chmin(x,y) (x = min(x,y))

//pairと順列全探索
int main(){
    int N;
    long double cnt=0;
    cin >> N;
    vector<pair<ll,ll>> A(N);

    for(int i = 0;i < N;i++)
        cin >> A[i].first >> A[i].second;

    vector<int> d(N);
    for(int i = 0;i < N;i++)
        d.at(i) = i;
    

    long double goukei = 0.0,ave;

    do{
        for(int i = 1;i < N;i++){
            goukei += hypot(A[d[i-1]].first - A[d[i]].first,A[d[i-1]].second - A[d[i]].second);
        }
        cnt++;    
    }while(next_permutation(d.begin(),d.end()));


   printf("%.10Lf\n",goukei/cnt); 
}
