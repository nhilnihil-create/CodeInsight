#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;

int main(){
    int N, M;
    long long int K;
    cin >> N >> M >> K;

    long long int A[N];
    rep(i, N){
        cin >> A[i];
    }

    long long int B[M];
    rep(i, M){
        cin >> B[i];
    }

    //ここから処理
    int time_A=0, time_B=0;
    int num_A=0, num_B=0;
    while(true){
        if(num_A == N) break;
        if(time_A+A[num_A] <= K) time_A += A[num_A++];
        else break;
    }
    //K時間でnum_A冊読める
    int ans=num_A;
    if(num_A == 0){
        while(true){
            if(num_B == M) break;
            if(time_B+B[num_B] <= K) time_B += B[num_B++];
            else break;
        }
        ans = num_B;
    }else{
        int n=num_A+1;
        rep(i, n){
            long long int K_sub = K-time_A;
            while(true){
                if(num_B == M) break;
                if(time_B+B[num_B] <= K_sub) time_B += B[num_B++];
                else break;
            }
            if(ans <= num_A+num_B) ans = num_A+num_B;
            time_A -= A[num_A-1];
            num_A--;
        }
    }

    cout << ans << endl;
}