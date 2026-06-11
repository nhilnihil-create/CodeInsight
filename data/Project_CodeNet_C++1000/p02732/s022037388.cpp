#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)

int main(){
    int N;
    cin >> N;
    vector<long long> A(N,0);
    rep(i,N)cin>>A[i];

    vector<long long> counts(N,0);

    rep(i,N){
        counts[A[i]-1] += 1;
    }

    long long sum = 0;
    rep(i,N){
        if(counts[i]==0)continue;
        sum += counts[i]*(counts[i]-1)/2;
    }

    rep(i,N){
        if(counts[A[i]-1] >= 2){
            long long delta = (counts[A[i]-1]-1)*(counts[A[i]-1]-2)/2 - counts[A[i]-1]*(counts[A[i]-1]-1)/2;
            cout << sum + delta << endl;
        }else{
            cout << sum << endl;
        }

    }

    return 0;

}