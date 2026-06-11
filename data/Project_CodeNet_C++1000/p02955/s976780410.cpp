#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;

int main() {
    int N,K;
    cin>>N>>K;
    vi A(N);
    int A_sum=0;
    for (int i = 0; i < N; i++){
        cin>>A[i];
        A_sum+=A[i];
    }
    for (int i = 1; i <= floor(sqrt(A_sum)); i++){
        if(A_sum%i!=0)continue;
        ll X=A_sum/i;
        vi B(N);
        ll B_sum=0;
        for (int j = 0; j < N; j++){
            B[j]=A[j]%X;
            B_sum+=B[j];
        }
        sort(B.begin(),B.end());
        ll minus=0;
        ll k=2000000000;
        for (int j = 0; j < N-1; j++){
            minus+=B[j];
            ll plus=X*(N-1-j)-(B_sum-minus);
            k=min(k,max(minus, plus));
        }
        if(k<=K){
            cout<<X<<endl;
            return 0;
        }
    }
    for (int i = floor(sqrt(A_sum)); i > 0; i--){
        if(A_sum%i!=0)continue;
        ll X=i;
        vi B(N);
        ll B_sum=0;
        for (int j = 0; j < N; j++){
            B[j]=A[j]%X;
            B_sum+=B[j];
        }
        sort(B.begin(),B.end());
        ll minus=0;
        ll k=2000000000;
        for (int j = 0; j < N-1; j++){
            minus+=B[j];
            ll plus=X*(N-1-j)-(B_sum-minus);
            k=min(k,max(minus, plus));
        }
        if(k<=K){
            cout<<X<<endl;
            return 0;
        }
    }
}