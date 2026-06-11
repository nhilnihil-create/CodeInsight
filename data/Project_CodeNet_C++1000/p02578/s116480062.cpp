#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<map>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main(){
    int n;
    cin>>n;
    int64_t a[n];
    int64_t cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i!=0){
            if(a[i-1]>a[i]){
                cnt+=(a[i-1]-a[i]);
                a[i]=a[i-1];
            }
        }
    }

    cout<<cnt<<endl;
}