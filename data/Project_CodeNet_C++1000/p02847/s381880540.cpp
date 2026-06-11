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
    string S;
    cin >> S;
    if(S == "MON")
        cout << 6 << endl;
    else if(S == "TUE")
        cout << 5 << endl;
    else if(S == "WED")
        cout << 4 << endl;
    else if(S == "THU")
        cout << 3 << endl;
    else if(S == "FRI")
        cout <<  2 << endl;
    else if(S == "SAT")
        cout << 1 << endl;
    else
    {
        cout << 7 << endl;
    }
    
}