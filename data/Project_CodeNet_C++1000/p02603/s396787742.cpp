#include<iostream>
using namespace std;
using ll=long long;

int main(){
    int N;
    cin>>N;
    int A[N+1];
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    ll sum=1000;
    for(int i=1;i+1<=N;i++){
        if(A[i]<A[i+1]){
            ll cnt=sum/A[i];
            sum+=cnt*(A[i+1]-A[i]);
        }
    }
    cout<<sum<<endl;
    return 0;
}