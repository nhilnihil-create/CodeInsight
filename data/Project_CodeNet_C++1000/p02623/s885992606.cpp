#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int N,M,K;
vector<ll> A,B;

bool isOK(int index) {
    int A_index=min(index,N);
    while (A_index>=0)
    {
        if(index-A_index>M)return false;
        if(A[A_index]+B[index-A_index]<=K)return true;
        A_index--;
    }
    return false;
}

int binary_search(){
    int ng = N+M+1;
    int ok = 0; 
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (isOK(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main() {
    cin>>N>>M>>K;
    A.resize(N+1);B.resize(M+1);
    A[0]=0;B[0]=0;
    for (int i = 1; i <= N; i++){
        int a;
        cin>>a;
        A[i]=A[i-1]+a;
    }
    for (int i = 1; i <= M; i++){
        int a;
        cin>>a;
        B[i]=B[i-1]+a;
    }
    cout<<binary_search()<<endl;
}