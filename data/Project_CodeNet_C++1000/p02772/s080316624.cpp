#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define rep(src,dst)    for(int i=src; i<dst;  i++)
#define rep2(src,dst)   for(int j=src; j<dst;  j++)
#define INF 1000000000000 //1e+12
#define MOD 10000007 //1e9+7
#define PI  acos(-1)
#define ll long long
template<typename T> inline void cMin(T* a, T* b)  {if(*a>*b) *a=*b;}
template<typename T> inline void chMax(T* a, T* b) {if(*a<*b) *a=*b;}
template<typename T> inline int  divUp(T a, T b)   {return ((a+b-1)/b);}
template<typename T> inline bool isEven(T a)       {return (a%2==0? true : false );}

int main(){
    int n; cin >> n;
    vector<int> even;
    rep(0,n){
        int a;
        cin >> a;
        if(!(a&1))  even.push_back(a);
    }
    rep(0,even.size()){
        if(!(even[i]%3==0 || even[i]%5==0)){
            cout << "DENIED" << endl;
            return 0;
        }
    }
    cout << "APPROVED" << endl;
    return 0;
}
/*

*/
