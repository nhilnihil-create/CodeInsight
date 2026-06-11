#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    long long n;
    cin >> n;

    map<long long, long long> T;
    long long num = n;

    for(long long i = 2; i * i <= num; i++){
        if(num % i != 0) continue;

        while(num % i == 0){
            if(T.find(i) == T.end()){
                T[i] = 1;
                num /= i;
            }
            else{
                T[i]++;
                num /= i;
            }
        }
    }
    if(num != 1) T[num] = 1;

    long long ans = 0;
    map<long long, long long>::iterator it;
    for(it = T.begin(); it != T.end(); it++){
        long long start = 1;
        long long cnt = 0;
        long long number = it->second;

        while(number - start >= 0){
            number -= start;
            cnt++;
            start++;
        }
        ans += cnt;
    }
    cout << ans << endl;
    return 0;
}