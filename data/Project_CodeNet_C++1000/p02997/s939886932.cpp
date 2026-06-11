#include <bits/stdc++.h>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    if((N-1)*(N-2)/2<K){
        cout << -1 << endl;
    }else{
        cout << N-1 + (N-1)*(N-2)/2 - K << endl;

        int count = (N-1)*(N-2)/2 - K;

        for(int i=2;i<=N;i++){
            cout << 1 << " " << i << endl;
        }
        
        for(int i=2;i<N;i++){
            for(int j=i+1;j<=N;j++){
                if(count==0){
                    return 0;
                }
                cout << i << " " << j << endl;
                count--;
            }
        }
    }
}