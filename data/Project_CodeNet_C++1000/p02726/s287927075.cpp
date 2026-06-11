#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main(){
    int N, X, Y;
    cin >> N >> X >>Y;

    vector<int> cnt(N, 0);
    for(int i=1; i<=N-1; i++){
        for(int j=i+1; j<=N; j++){
            cnt[min(abs(i-j), min(abs(X-i)+1+abs(Y-j), abs(Y-i)+1+abs(X-j)))]++;
            //cout<<min(abs(i-j), min(abs(X-i)+1+abs(Y-j), abs(Y-i)+1+abs(X-j)))<<" : "<<i<<" --> "<<j<<endl; 
        }
    }

    for(int i=1; i<N; i++){
        cout<<cnt[i]<<endl;
    }

    return 0;

}