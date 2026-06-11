#include <bits/stdc++.h>

//#define DEBUG

#ifdef DEBUG
using std::endl;
std::ifstream cin("input.txt");
std::ofstream cout("output.txt");
#endif // DEBUG
#ifndef DEBUG
using namespace std;
#endif // DEBUG

template <class T>
void print_vect(T v){
    for(int i = 0 ; i < v .size(); i++) cout << v[i] << " ";
    cout << endl;
}

int gcd(int a , int b){
    if( a < b){
        return gcd(b, a);
    }else{
        if( b == 0){
            return a;
        }else{
            return gcd(b , a % b);
        }
    }
 
}

uint64_t pow(uint64_t a , uint64_t p, uint64_t mod){
    if( p < 2){
        uint64_t ans = 1;
        while(p--){
            ans =  (ans * a) % mod;
        }
        return ans;
    }else{
        if( p % 2){
            uint64_t ans = pow(a, p / 2, mod);
            uint64_t real_ans = (ans * ans) % mod;
            real_ans = (real_ans * a) % mod;
            return real_ans;
        }else{
            uint64_t ans = pow(a , p /2, mod);
            return (ans * ans) % mod;
        }
    }
}

uint64_t count_turple(uint64_t N, uint64_t K){
    std::vector<uint64_t> count_gcd(K+1, 0);
    const uint64_t MOD = 1000000007;
    count_gcd[K] = 1;
    for(uint64_t j = K - 1 ; j >= 1 ; j--){
        uint64_t fist_count = pow( K / j, N, MOD);
        //cout << "first count " << fist_count << endl;
        uint64_t multiple = 2;
        while(j <= K / multiple){
            fist_count = (fist_count + MOD - count_gcd[multiple * j]) % MOD;
            multiple++;
        }
        count_gcd[j] = fist_count;
        //cout << "count gcd = " << j << " -> " << fist_count << endl;
    }
    uint64_t ans = 0;
    for(uint64_t i = 1 ; i <= K ; i++){
        ans =  (ans + count_gcd[i] * i) % MOD;
    }
    return ans;
}

void func_to_create(){
    uint64_t N, K;
    cin >> N >> K;
    uint64_t ans = count_turple(N, K);
    cout << ans << endl;
}

int main()
{
    //making data IO Fast
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    /***************************/

    #ifdef DEBUG
    int TEST_CASES = 3;
    while(TEST_CASES--){
    #endif // DEBBUG

    func_to_create();

    #ifdef DEBUG
    }
    #endif // DEBUG


    return 0;
}
