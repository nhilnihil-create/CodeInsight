#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mx = 1e7 + 7; //dont use too large array in every code

ll par[mx]; //dont use long long if u don't need to store large values. be extra careful.
//ll p_u, p_v; //ei duita globally declare korar dorkar nai kono... code e vul hoite pare

//par[x] hocche x er immidiate parent.
//x jei set e ase tar parent ber kore find_parent(x) dia.
//par[x] abar x er set er parent o hoite pare, majhe majhe, jodi 
//actual parent ta par[x] e thake. bt set gula union korle value
//gula ulta palta hoia jay. find_parent function ta call korle
//auto value gula correctly boshe. tai always x er set er actual
//parent bair korte find_parent(x) function call korte hobe.

ll find_parent(ll x) {
    if(x == par[x]) return x;

    //x er parent je, tar actual parent return korba
    //not par[x] = find_parent(x), eta to infinite loop e poira gelo
    return par[x] = find_parent(par[x]); //return korte hobe
}



void join(ll u, ll v) {

    ll p_u = find_parent(u);
    ll p_v = find_parent(v);

   if(p_u == p_v) return; //par[u] ashole u er set er parent na. 
                //find_parent(u) jei node ta return korbe, oita u er set er parent.
                //par array ta ei parent bair korte help kore.

   par[p_u] = p_v; //par[u] = p_v na. u er set er parent je, tar parent p_v diba.
                    //mane par[p_u] = p_v diba.
}

int main() {
    ll n, q;  cin >> n >> q;
    for(ll i = 0; i < n; i++) par[i] = i;

    while(q--) {
        ll t; cin >> t;
        if(t == 1) {
            ll u, v;  cin >> u >> v;
            ll p_u = par[u]; //no no
            ll p_v = par[v]; //no no

             //par[u] kintu u er parent na... 
             //not always
             //find_parent(u) dile actual u er parent ase
             //par[u] dile ekta node ashe, tar jodi arekta parent thake?
             //shetar jodi arekta thake?
             //erokom dada por dada hoia finally jei purbo purush
             //shei ashol parent
             //jeta bair kore find_parent(u) function ta.

             //so emon:
             p_u = find_parent(u), p_v = find_parent(v);
            if(p_u == p_v) cout << 1 << endl;
            else cout << 0 << endl;
        }

        else if( t == 0) {
            ll u, v;  cin >> u >> v;
            join(u, v);
        }
    }

    return 0;
}