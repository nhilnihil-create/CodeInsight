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
    vector<int> v(N);

    for(int i = 0;i < N;i++)
        cin >> v.at(i);

    double goukei = 0;

    sort(v.begin(),v.end());

    for(int i = 0;i < N - 1;i++){
        if(i == 0){
            goukei = v.at(i) + v.at(i+1);
            goukei /= 2.0;
        }else{
            goukei += v.at(i+1);
            goukei /= 2.0;
        }
    }

    printf("%.12f\n",goukei);


}