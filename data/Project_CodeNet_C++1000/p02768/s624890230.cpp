#include <iostream>

#define MOD 1000000007

typedef long long ll;

using namespace std;

ll eleva(ll num, ll elevado){
    ll ans = 0;
    
    if(elevado == 0) return 1;

    if(elevado % 2 == 0){
        
        ans = eleva(num, elevado/2);        
        ans *= ans;
        return ans % MOD;
    }else{

        ans = eleva(num, elevado/2);
        ans = ((ans * ans) % MOD) * num;    
        return ans % MOD;
    }
}

ll subMod(ll x, ll y){

    ll ans = x - y;

    if(ans < 0)
        return ans + MOD;
    else
        return ans % MOD;
}

// n é o total
// k é qntos eu posso escolher
// Combinação de n escolhendo k coisas
// C = (n!) / (n - k)!(k)!
ll comb(ll n, ll k){
    ll ans = 1, deno = 1, res;

    // calculando a parte de cima da função da combinação
    for(ll i = n; i >= (n - k + 1); i--){
        ans = (ans * i) % MOD;
    }

    for(ll i = 1; i <= k; i++){
        deno = (deno * i) % MOD;
    }

    // inversa modular: Um número que vc tem q multiplicar a ele
    // para funcionar como se fosse uma divisão    
    // Por q estamos usando MOD não podemos fazer a divisão ali em cima normalzinha
    // entao vai usar o pequeno teorema d fermat
    // ans * inverso modular do denominador
    
    res = (ans * eleva(deno, MOD - 2)) % MOD;

    return res;
}

int main(){

    ll t, a, b, tot = 0;
    cin >> t >> a >> b;

    tot = eleva(2, t);
    tot = subMod(tot, 1);

    tot = subMod(tot, comb(t, a));
    tot = subMod(tot, comb(t, b));

    cout << tot << endl;

    return 0;
}
