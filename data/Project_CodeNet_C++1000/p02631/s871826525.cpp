#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int n;
    cin>>n;
    int A[n];
    rep(i, n) cin>>A[i];

    int x_or=0;
    rep(i, n) x_or=x_or^A[i];
    rep(i, n){
        int num=x_or^A[i];
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}