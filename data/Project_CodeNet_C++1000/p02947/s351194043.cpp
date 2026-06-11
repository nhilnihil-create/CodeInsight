#include <bits/stdc++.h>
#include <string>
#include <cstring>
#include <algorithm>
#include <math.h>
#include <map>
#include <bitset>
#include <cmath>
#include <set>

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
    ll N,rs=0,ans=0;
    cin >> N;
    vector<string> S(N);
    string hako;

    for(ll i = 0;i < N;i++){
        cin >> S.at(i);
        sort(S.at(i).begin(),S.at(i).end());
    }
    sort(S.begin(),S.end());

    for(ll i = 0;i < N;i++){
        if(i == 0)
            hako = S.at(i);
        else{
            if(hako == S.at(i)){
                rs++;
                ans +=rs; 
            }else{
                rs = 0;
                hako = S.at(i);
            }
        }
    }

    cout << ans << endl;

}