#include <bits/stdc++.h>
using namespace std;
#define rep(src,dst)    for(int i=src; i<dst;  i++)
#define rep2(src,dst)   for(int j=src; j<dst;  j++)
#define INF 1000000000000 //1e12
#define MOD 1000000007 //1e9+7
#define PI  acos(-1)
#define ll long long
template<typename T> inline void cMin(T* a, T* b)  {if(*a>*b) *a=*b;}
template<typename T> inline void chMax(T* a, T* b) {if(*a<*b) *a=*b;}
template<typename T> inline int  div(T a, T b)     {return ((a+b-1)/b);}
template<typename T> inline bool eoVerify(T a)     {return (!(a&1)? true : false );}

/***********************
* O(1)                 *
* O(logN)              *
* O(N)                 *
* O(NlogN)             *
* O(N^2)               *
* O(N^3)               *
* O(k^N)               *
* O(N!)                *
************************/

int main(){
    string str; cin >> str;
    string strc;
    ll ans=0;
    rep(0,str.length()){
        strc = str[i];
        ans += stol(strc);
    }
    cout << (!(ans%9)? "Yes" : "No");
    return 0;
}
