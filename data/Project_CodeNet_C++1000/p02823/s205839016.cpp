#include<iostream>
#include<algorithm>
using namespace std;

long long findAns(long long n, long long a, long long b){
    if(a - 1 < n - b) return a + (b - a - 1)/2;
    else return n - b + 1 + (b - a - 1)/2;
}

int main(){
    long long A, B, N;
    cin >> N >> A >> B;

    if(N == 2){
        cout << 1 << endl;
    } else if((B - A) % 2 == 0){
        cout << (B - A) / 2 << endl;
    } else{
        cout << findAns(N, A, B) << endl;
    }
}
