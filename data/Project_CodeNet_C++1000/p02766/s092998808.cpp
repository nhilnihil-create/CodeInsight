#include<iostream>
using ll=long long;
using namespace std;

int main(){
    ll N;
    int K;
    cin>>N>>K;
    int cnt=0;
    while(N!=0){
        N/=K;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}