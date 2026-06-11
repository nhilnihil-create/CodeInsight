#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N; 
    cin >> N;
    vector<ll> A(N);
    vector<ll> num(N+1, 0);
    rep(i, N){
        cin>>A[i];
        num[A[i]]++;
    }

    ll sum=0;
    rep(i, N){
        int aaaa=i+1;
        sum+=num[aaaa]*(num[aaaa]-1)/2;
    }

    rep(i, N){
        ll sum_sub=sum;
        sum_sub-=(num[A[i]]-1)*num[A[i]]/2;
        sum_sub+=(num[A[i]]-2)*(num[A[i]]-1)/2;
        cout<<sum_sub<<endl;
    }
    return 0;
}