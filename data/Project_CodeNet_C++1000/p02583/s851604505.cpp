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
    int l[n];
    rep(i,n){
        cin>>l[i];
    }

    int cnt=0;

    for(int i=0;i+2<n;i++){
        for(int j=i+1;j+1<n;j++){
            for(int k=j+1;k<n;k++){
                if(l[i]!=l[j]&&l[j]!=l[k]&&l[k]!=l[i]){
                    if(l[i]<l[j]+l[k]&&l[j]<l[k]+l[i]&&l[k]<l[i]+l[j]){
                        cnt++;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
}