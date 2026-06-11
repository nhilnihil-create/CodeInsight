#include <iostream>
#include <set>

bool ok(const long long N, const long long num){
    return (num >= 2 && num <= N);
}

bool check(long long N, const long long num){
    while(N % num == 0) N /= num;
    return ((N - 1) % num == 0);
}

int main(){
    long long N;
    std::cin >> N;
    long long ans = 0;
    for(long long i = 1; i * i <= N - 1; ++i){
        if((N - 1) % i == 0){
            if(ok(N, i)) ++ans;
            if(i != (N - 1) / i && ok(N, (N - 1) / i)) ++ans;
        }
    }
    for(long long i = 1; i * i <= N; ++i){
        if(N % i == 0){
            if(ok(N, i) && check(N, i)) ++ans;
            if(i != N / i && ok(N, N / i) && check(N, N / i)) ++ans;
        }
    }
    std::cout << ans << "\n";
}