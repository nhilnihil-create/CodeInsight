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

#define INF 1000000000000
#define MOD 1000000007 //10^9+7:合同式の法

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    int N;
    cin >> N;
    vector<int> A(N);

    for(int i = 0;i < N;i++)
        cin >> A.at(i);

    double ans = 0,goukei = 0;

    for(int i = 0;i < N;i++){
        goukei += 1 / (double)A.at(i);
    }

    ans = 1 / goukei;

    printf("%.12f\n",ans);


}