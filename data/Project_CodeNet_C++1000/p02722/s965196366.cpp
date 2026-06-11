#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin >> n;
    if(n == 2){
        cout << '1';
        return 0;
    }
    long long cnt = 0;
    for(long long i = 2; i <= sqrt(n - 1); i++){
        if((n - 1) % i == 0){
            cnt++;
            if((n - 1)/i != i){
                cnt++;
            }
        }
    }
    for(long long i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            long long m = n;
            while(m % i == 0){
                m = m/i;
            }
            if(m % i == 1){
                cnt++;
            }
            long long j = n/i;
            if(j == i){
                continue;
            }
            m = n;
            while(m % j == 0){
                m = m/j;
            }
            if(m % j == 1){
                cnt++;
            }
        }
    }
    cnt += 2;
    cout << cnt;
    return 0;
}