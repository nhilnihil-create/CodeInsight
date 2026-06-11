#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1LL << 60;


int main(void){
    int n;
    cin >> n;
    n%=10;
    int a[5]={2,4,5,7,9},b[4]={0,1,6,8};
    REP(i,5){
        if(n==a[i]){
            cout << "hon";
            return 0;
        }
    }
    REP(i,4){
        if(n==b[i]){
            cout << "pon";
            return 0;            
        }
    }
    cout << "bon";
    return 0;
}