#include<iostream>
#include<cmath>
using namespace std;

long long ck_keta(long long x);

int main(){
    long long N;
    long long ans = 0, n;

    std::cin >> N;

    for(long long i = 1; i <= N; i++){
        n = ck_keta(i);
        ans = ans + n%2;
    }

    std::cout << ans;
}

long long ck_keta(long long x){
    long long keta = 1;
    double d_x = round((double)x);
    while(d_x >= 10.0){
        d_x = d_x/10.0;
        keta++;
    }
    return keta;
}