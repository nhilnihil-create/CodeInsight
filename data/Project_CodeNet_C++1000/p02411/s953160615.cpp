#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<utility>
#include<map>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,m,n) for(ll i=m;i<n;i++)
#define REPR(i,n) for(ll i=n-1;i>=0;i--)
#define FORR(i,n,m) for(ll i=n-1;i>=m;i--)
#define all(in) in.begin(),in.end()
#define ALL(in,K) in,in+K
#define INF 100000000
#define MOD 100000007
#define SIZE 100005
#define pi  3.14159265358979323846
 
int main(){
    ll m,f,r;
    ll roop = 0;
    char result[52];
    while(1){
        cin >> m >> f >> r;
        if(m == -1 && f == -1 && r==-1){
            break;
        }else if(m == -1 || f == -1 || m+f < 30){
            result[roop] = 'F';
        }else if(m+f>=80){
            result[roop] = 'A';
        }else if(m+f>=65){
            result[roop] = 'B';
        }else if(m+f>=50 || (m+f>=30&&r>=50)){
            result[roop] = 'C';
        }else{
            result[roop] = 'D';
        }
        roop++;
    }
    REP(i,roop){
        cout << result[i] << endl;
        }
    return 0;
}
