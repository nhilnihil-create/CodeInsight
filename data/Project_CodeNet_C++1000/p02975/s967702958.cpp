#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long a[n];
    long long sum = 0;
    for(long long i = 0; i < n; i++){
        cin >> a[i];
        sum = sum^a[i];
    }

    //printf("%lld\n", sum);
    if(sum == 0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }

    return 0;

}