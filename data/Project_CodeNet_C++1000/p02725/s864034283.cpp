#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n+1); i++)
int main() {
    int K,N;
    cin>>K>>N;
    vector<int>A(N);
    int ans=K;
     int m=0;
    rep(i,N){
        cin>>A[i];
        if(i!=0){
            if(m<abs(A[i]-A[i-1])){
                m=abs(A[i]-A[i-1]);
            }
        }
    }
    if(m<K-abs(A[0]-A[N-1])){
        m=K-abs(A[0]-A[N-1]);
    }
    cout<<ans-m<<endl;
}