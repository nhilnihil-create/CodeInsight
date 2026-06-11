#pragma GCC target ("avx2")
#pragma GCC optimize ("unroll-loops")
#pragma GCC optimize ("O3")
#include "bits/stdc++.h"
#include <unordered_set>
#include <unordered_map>
#include <random>
using namespace std;
typedef long long ll;
const ll MOD = 1'000'000'007LL; /*998'244'353LL;*/
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
const int dx[4]={ 1,0,-1,0 };
const int dy[4]={ 0,1,0,-1 };

template<typename T>
T gcd(T a, T b){
    if(b > a) swap(a, b);
    T tmp;
    while(b != 0){
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

vector<pair<long long, int>> prime_factorization(long long n){
    vector<pair<long long, int>> ret;
    for(long long i=2; i*i<=n; i++){
        if(n%i == 0) ret.push_back({ i, 0 });
        while(n%i == 0){
            ret.back().second++;
            n /= i;
        }
    }
    if(n != 1) ret.push_back({ n, 1 });
    return ret;
}

int N;
int A[1000000];

bool exist[1000001] ={};

signed main(){
    cin >> N;
    rep(i, N) cin >> A[i];
    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(A, A+N, engine);

    int g = A[0];
    for(int i=1; i<N; i++) g = gcd(g, A[i]);
    if(g != 1){
        cout << "not coprime" << endl;
        return 0;
    }

    rep(i, N){
        auto v = prime_factorization(A[i]);
        rep(j, v.size()){
            if(exist[v[j].first]){
                cout << "setwise coprime" << endl;
                return 0;
            }
            exist[v[j].first] = true;
        }
    }

    cout << "pairwise coprime" << endl;
}