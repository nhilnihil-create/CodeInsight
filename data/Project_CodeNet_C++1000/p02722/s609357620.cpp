#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,ans=0;

    cin >> N;

    for(long long int i=2;i*i<=N;i++){
        if(N%i==0){
            long long int other = N/i;

            long long int tmp = N;

            while(tmp%i==0){
                tmp /= i;
            }
            if(tmp%i == 1){
                ans++;
            }

            if(i*i != N){

                tmp = N;
                while(tmp%other==0){
                    tmp /= other;
                }
                if(tmp%other == 1){
                    ans++;
                }
            }
        }
    }

    for(long long int i=2;i*i<=N-1;i++){
        if((N-1)%i==0){
            if(i*i==N-1){
                ans++;
            }else{
                ans += 2;
            }
        }
    }

    if(N==2){
        cout << 1 << endl;
    }else{
        cout << ans+2 << endl;
    }
}