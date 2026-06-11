#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

#define FOR(i,N) for(int i=0;i<N;i++)

int main(){
    long long N,H,W,Q,M=0,cnt=0,max=0,sum=0;
    cin >> N;
    vector<long>A(N,0),cnta(N,0);
    FOR(i,N){
        cin >> A[i];
        cnta[A[i]-1]++;
    }
    FOR(i,N){
        if(cnta[i]>1)max += cnta[i]*(cnta[i]-1)/2;
    }
    FOR(i,N){
        cnt = max;
        if(cnta[A[i]-1]>1){
            cnt += ((cnta[A[i]-1]-1)*(cnta[A[i]-1]-2)/2) - (cnta[A[i]-1]*(cnta[A[i]-1]-1)/2);
        }
        cout << cnt << endl;
    }
}