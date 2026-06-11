#include <iostream>
#include <string>
#include <vector>
using ll=long long;
using namespace std;

int main(){
    string S;
    cin>>S;
    int size=S.size();
    vector<int> N(size);
    vector<int> rN(size);
    N[0]=(int)S[size-1]-'0';
    rN[0]=10-N[0];
    for(int i=1;i<size;i++){
        N[i]=(int)S[size-i-1]-'0';
        rN[i]=9-N[i];
    }

    vector<ll> dp1(size+1);
    vector<ll> dp2(size+1);
    dp1[0]=0;dp2[0]=0;
    for(int i=1;i<size+1;i++){
        dp1[i]=min(N[i-1]+dp1[i-1],N[i-1]+1+dp2[i-1]);
        dp2[i]=min(rN[i-1]+dp2[i-1],rN[i-1]+1+dp1[i-1]);
    }
/*
    for(auto p:dp1){
        cout<<p<<" ";
    }
    cout<<endl;
    for(auto p:dp2){
        cout<<p<<" ";
    }
    cout<<endl;
    */
    cout<<min(dp1[size],dp2[size]+1)<<endl;

    return 0;
}