#include <bits/stdc++.h>
using namespace std;

#define lint long long


lint MOD = 1000000007;

class Combination_mod{
public:
    Combination_mod(lint mod);
    lint power_mod(lint a, lint p);
    lint div_mod(lint A, lint B);
    lint combi_mod(lint n, lint k);
    lint factorial_mod(lint n);
    
private:
    lint mod;
    lint MAX_N = 0; //for memory
    vector<lint> Factorial; //for memory
};

Combination_mod::Combination_mod(lint MOD){
    mod = MOD; //initialize mod
    Factorial.resize(100000, (lint)0); //@@@@@@@@@@@@@@@ ADJUST THE SIZE HERE!!! @@@@@@@@@@@@@@@
    
}

// calculate a^p
lint Combination_mod::power_mod(lint a, lint p){
    a %= mod;
    
    if(p == 1){
        return a;
    }
    
    if(p >= mod){
        return 0;
    }
    
    if(p % 2 == 0){
        lint tmp = power_mod(a, p / 2);
        return (tmp * tmp) % mod;
    } else {
        return (power_mod(a, p - 1) * a) % mod;
    }
}

lint Combination_mod::div_mod(lint A, lint B){
    A %= mod; B %= mod;
    lint ans;
    lint inv_B;
    inv_B = power_mod(B, mod - 2);
    ans = (A * inv_B) % mod;
    return ans;
}

lint Combination_mod::combi_mod(lint n, lint k){
    lint ans;
    if(k < 0 || n < k) return 0;
    if(k == 0 || n == k) return 1;
    
    lint div = (factorial_mod(k) * factorial_mod(n - k)) % mod;
    lint num = factorial_mod(n);
    
    ans = div_mod(num, div);
    return ans;
}

lint Combination_mod::factorial_mod(lint n){
    if(n==1) return 1;
    if(n < 1) return 0;
    if(Factorial[n] != 0){
        return Factorial[n];
    } else {
        lint tmp = factorial_mod(n - 1) * n;
        tmp %= mod;
        Factorial[n] = tmp;
        return tmp;
    }
}

int main(){
    lint N, K;
    cin >> N >> K;
    

    
    Combination_mod CM(MOD);
    
    for(int i = 1; i <= K; ++i){
        if(N == K){
            if(i == 1) cout << 1 << endl;
            else cout << 0 << endl;
            continue;
        }
        lint Blue;
        Blue = CM.combi_mod(K - 1, i - 1);
        //cout << Blue << " ";
        
        lint Red = 0;
        for(int j = -1; j < 2; ++j){
            Red += CM.combi_mod(N - K - 1, i - j - 1) * (j == 0 ? 2 : 1);
            
            //cout << CM.combi_mod(N - K - 1, i - j - 1) << " ";
            Red %= MOD;
            
        }
        
        cout << ((Blue * Red) % MOD) << endl;
    }

    
}