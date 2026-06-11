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
#define JUUHATI 1000000000000000000 
#define JUUHATIPLUS 1000000000000000001 

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

int main(){
    int N,M,ansN = 0,ansM=0;
    cin >> N >> M;

    if(N >= 2){
        ansN = 1;
        for(int i = N -1;i <= N;i++)
            ansN *= i;

        ansN /= 2;
    }

    if(M >= 2){
        ansM = 1;
        for(int i = M -1;i <= M;i++)
            ansM *= i;
        ansM /= 2;
    }

    cout << ansN + ansM << endl;

    

}