#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    
    vector<long long> Acnt(N+1,0);
    
    for(auto x: A){
        Acnt.at(x)++;
    }

    long long s=0;
    for (int i = 1; i < N+1; i++){
        if(Acnt.at(i)!=0){
            s=s+Acnt.at(i)*(Acnt.at(i)-1)/2;
        }
    }

    for (auto Ak: A){
        long long ans=s-Acnt.at(Ak)+1;
        printf("%lld\n",ans);
    }
    
    
}