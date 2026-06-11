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
    int n, x, t;
    cin >> n >> x >> t;
    int tmp = n%x;
    int ret = n/x * t;

    if(x>=n){
        cout << t << endl;
        return 0;
    }
    cout << (tmp>0? ret + t : ret);
    return 0;
}
