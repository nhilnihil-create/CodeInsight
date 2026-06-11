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
    string S,revS,partS,partS2;
    cin >> S;
    revS = S;
    int N;
    N = S.size();
    bool fla = true;

    reverse(revS.begin(),revS.end());

    if(revS != S)
        fla = false;

    for(int i = 0;i < (N -1)/2;i++){
        if(i == (N -1)/2 - 1){
            partS += S.at(i);
            revS = partS;
            reverse(revS.begin(),revS.end());
            if(partS != revS)
                fla = false;
        }
        partS += S.at(i);

    }

    for(int i = (N+3)/2 -1;i < N;i++){
        if(i == N - 1){
            partS2 += S.at(i);
            revS = partS2;
            reverse(revS.begin(),revS.end());
            if(partS2 != revS)
                fla = false;
        }
        partS2 += S.at(i);

    }

    if(fla)
        cout << "Yes" << endl;
    else
    {
        cout << "No" << endl;
    }
    



    

}