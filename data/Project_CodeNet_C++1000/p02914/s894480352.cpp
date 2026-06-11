#include <iostream>
#include <bitset>

using namespace std;
typedef long long ll;

long A[100000];

long b[60];

void init(){
    long m = 1;
    for(int i = 0; i < 60; i++){
        b[i] = m;
        m = m<<1;
    }
}

void sweep(long A[], int N){
    int cur = 0;
    for(int i = 0; i < 60 && cur < N ; i++){
        if(!(A[cur]&b[59-i])){
            for(int j = cur; j < N; j++){
                if(A[j]&b[59-i]) {
                    swap(A[cur], A[j]);
                    break;
                }
            } 
        }
        if(A[cur]&b[59-i]){
            for(int j = 0; j < N; j++){
                if(j == cur) continue;
                if(A[j]&b[59-i]){
                    A[j] = A[j]^A[cur];
                }
            }
            cur++;
        }
    }
}

int main(){
    init();
    int N;
    cin >> N;
    long total = 0;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        total ^= A[i];
    }
    for(int i = 59; i >= 0; i--){
        long m = (long)1<<i;
        if(m&total){
            for(int j = 0; j < N; j++){
                if(A[j]&m) A[j] ^= m;
            }
        }
    }
    
    sweep(A, N);
    
    int cur = 0;
    long ans = 0;
    long tmp = 0;
    
    for(int i = 0; i < N; i++) ans ^= A[i];
    ans *= 2;
    ans += total;
    cout << ans << endl;
}