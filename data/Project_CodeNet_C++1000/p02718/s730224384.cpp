#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, M;
    cin >> N >> M;
    int A[N]; 
    rep(i, N) cin >> A[i];

    int num=0;
    rep(i, N) num+=A[i];
    double border=num/(4.0*M);
    int sum=0;
    rep(i, N) if(A[i]>=border) sum++;
    if(sum>=M) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}