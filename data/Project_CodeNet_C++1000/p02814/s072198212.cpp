#include <iostream>
using namespace std;

long long gcd(long long a, long long b){
    // 最大公約数
    // ユークリッドの互除法
    if(a < b){
        long long temp = a;
        a = b;
        b = temp;
    }
    long long r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

long long lcm(long long a, long long b){
    // 最小公倍数
    return a * b / gcd(a, b);
}

int main(){
    // ai が 2 で割り切れる回数と aj が 2 で割り切れる回数が異なるような i, j が存在するとき、条件を満たす X はありません。
    long long n, m;
    cin >> n >> m;
    long long a, l, pw2_num = 0;
    for(long long i = 0; i < n; i++){
        cin >> a;
        if(i == 0){
            l = a / 2;
            while(a % 2 == 0){
                pw2_num++;
                a /= 2;
            }
            continue;
        }
        l = lcm(l, a / 2);
        if(l > m){
            cout << 0;
            return 0;
        }
        int temp = 0;
        while(a % 2 == 0){
            temp++;
            a /= 2;
        }
        if(temp != pw2_num){
            cout << 0;
            return 0;
        }
    }
    long long cnt = 0;
    for(long long i = 1; ; i += 2){
        if(l * i <= m) cnt++;
        else break;
    }
    cout << cnt;
    return 0;
}