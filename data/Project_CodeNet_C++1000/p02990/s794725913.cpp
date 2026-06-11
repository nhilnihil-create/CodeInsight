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
    
private:
    lint mod;
    vector<lint> power_2; //2の累乗のリスト
};

Combination_mod::Combination_mod(lint MOD){
    mod = MOD; //mod の初期化
}

//a^pを計算する
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
    lint div = 1;
    lint num = 1;
    if(k < 0) return 0;
    if(k == 0) return 1;
    
    for(lint i = 1; i <= k; ++i){
        div = (div * i) % mod;
    }
    
    for(lint i = n - k + 1; i <= n; ++i){
        num = (num * i) % mod;
    }
    
    ans = div_mod(num, div);
    return ans;
}


int main(){
    lint N, K;
    cin >> N >> K;
    

    
    Combination_mod CM(MOD);
    
    for(int i = 1; i <= K; ++i){
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
