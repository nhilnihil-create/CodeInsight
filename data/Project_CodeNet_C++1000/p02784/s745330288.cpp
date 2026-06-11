#include <bits/stdc++.h>
using namespace std;
#define rep(k,dst)    for(int i=k; i<dst;  i++)
#define rep2(k,dst)   for(int j=k; j<dst;  j++)
#define INF 1000000000000 //1e+12
#define MOD 10000007 //1e9+7
#define ll long long
#define pb pop_back
template<typename T> inline void chMin(T* a, T* b) {if(*a>*b) *a=*b;}
template<typename T> inline void chMax(T* a, T* b) {if(*a<*b) *a=*b;}
template<typename T> inline int  divUp(T a, T b)   {return ((a+b-1)/b);}
const double PI = acos(-1);

int main(){
    ll h, n; cin >> h >> n;
    ll AllDamage=0;
    int a;
    rep(0,n){
        cin >> a;
        AllDamage += a;
    }
    if(AllDamage >= h) cout << "Yes" << endl;
    else               cout << "No"  << endl;
    return 0;
}
/*

*/
