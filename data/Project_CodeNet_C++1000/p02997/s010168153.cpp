#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,K;
    cin >> N >> K;
    ll edgeNum = (N-1)*(N-2)/2;
    if(edgeNum<K){
        cout << -1 <<endl;
        return 0;
    }
    cout << N-1 +edgeNum -K <<endl;
    for(int i=1;i<N;i++){
        cout << i <<" "<< N <<endl; 
    }
    if(edgeNum == K){
        return 0;
    }
    int t = 1;
    while(true){
        for(int i=1;i<N;i++){
            if(i+t >= N){
                cout << i <<" " <<i+t-(N-1) << endl;
            }else{
                cout << i <<" "<< i+t << endl;
            }
            edgeNum--;
             if(edgeNum == K){
                return 0;
            }
        }
        t++;
    }

    return 0;
}