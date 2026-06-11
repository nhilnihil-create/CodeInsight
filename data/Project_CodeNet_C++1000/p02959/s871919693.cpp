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
    ll N,ans1= 0;
    cin >> N;
    vector<ll> A(N+1),B(N+1);
    
    for(ll i = 0;i <= N;i++){
        cin >> A.at(i);
    }

    for(ll i = 0;i < N;i++)
        cin >> B.at(i);


    for(ll i = 0;i < N;i++){
        if(A.at(i) >= B.at(i)){
            ans1 += B.at(i);
        }
        else{
            ans1 += A.at(i);
            B.at(i) -= A.at(i);
            A.at(i) = 0;
            if(B.at(i) >= A.at(i+1)){
                ans1 += A.at(i+1);
                A.at(i+1) = 0; 
            }else{
                ans1 += B.at(i);
                A.at(i+1) -= B.at(i);
            }
        }
    }

    cout << ans1 << endl;

}