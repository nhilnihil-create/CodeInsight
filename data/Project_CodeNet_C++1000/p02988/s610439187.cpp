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
    int N,ans=0;
    cin >> N;
    vector<int>p(N);
    
    for(int i =0;i < N;i++)
        cin >> p.at(i);

    for(int i = 1;i < N-1;i++){
        if(p.at(i) > p.at(i-1)){
            if(p.at(i) < p.at(i+1))
                ans++;
        }else if(p.at(i) < p.at(i-1)){
            if(p.at(i) > p.at(i+1))
                ans++;
        }
    }
    cout << ans << endl;
}