#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long a[n+1], b[n+1];

    for(long long i = 0; i <= n; i++){
        cin >> a[i];
    }

    if(n == 0){
        if(a[0] == 1){
            cout << 1 << endl;
            return 0;
        }
        else{
            cout << -1 << endl;
            return 0;
        }
    }
    if(a[0] != 0){
        cout << -1 << endl;
        return 0;
    }

    b[0] = 1 - a[0];
    vector<long long> A(n+2, 0);
    for(long long i = 0; i <= n; i++){
        A[i+1] = A[i] + a[i];
    }

    bool flag = true;
    for(long long i = 1; i <= n; i++){
        long long sum = A[n+1] - A[i+1];
        b[i] = min(sum, 2*b[i-1] - a[i]);
        //printf("sum %lld 2*b[i-1] - a[i] %lld\n", sum, 2*b[i-1] - a[i]);
        if(b[i] < 0){
            flag = false;
            break;
        }
    }

    if(flag == false){
        printf("-1\n");
        return 0;
    }

    long long count = 0;
    for(long long i = 0; i <= n; i++){
        count += a[i] + b[i];
    }

    cout << count << endl;

    return 0;
}