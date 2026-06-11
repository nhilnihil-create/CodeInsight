#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint mod = 1e9 + 7;
#define all(x) (x).begin(), (x).end()
#define bitcount(n) __builtin_popcountl((lint)(n))
#define fcout cout << fixed << setprecision(15)
#define highest(x) (63 - __builtin_clzl(x))
template<class T> inline void YES(T condition){ if(condition) cout << "YES" << endl; else cout << "NO" << endl; }
template<class T> inline void Yes(T condition){ if(condition) cout << "Yes" << endl; else cout << "No" << endl; }
template<class T = string, class U = char>int character_count(T text, U character){ int ans = 0; for(U i: text){ ans += (i == character); } return ans; }
lint power(lint base, lint exponent, lint module){ if(exponent % 2){ return power(base, exponent - 1, module) * base % module; }else if(exponent){ lint root_ans = power(base, exponent / 2, module); return root_ans * root_ans % module; }else{ return 1; }}
struct position{ int y, x; }; position mv[4] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}}; // double euclidean(position first, position second){ return sqrt((second.x - first.x) * (second.x - first.x) + (second.y - first.y) * (second.y - first.y)); }
template<class T, class U> string to_string(pair<T, U> x){ return to_string(x.first) + "," + to_string(x.second); } string to_string(string x){ return x; }
template<class itr> void array_output(itr start, itr goal){ string ans; for(auto i = start; i != goal; i++) ans += to_string(*i) + " "; if(!ans.empty()) ans.pop_back(); cout << ans << endl; }
template<class itr> void cins(itr first, itr last){ for(auto i = first; i != last; i++){ cin >> (*i); } }
template<class T> T gcd(T a, T b){ if(a && b){ return gcd(min(a, b), max(a, b) % min(a, b)); }else{ return a; }} template<class T> T lcm(T a, T b){ return a / gcd(a, b) * b; }
struct combination{ vector<lint> fact, inv; combination(int sz) : fact(sz + 1), inv(sz + 1){ fact[0] = 1; for(int i = 1; i <= sz; i++){ fact[i] = fact[i - 1] * i % mod; } inv[sz] = power(fact[sz], mod - 2, mod); for(int i = sz - 1; i >= 0; i--){ inv[i] = inv[i + 1] * (i + 1) % mod; } } lint C(int p, int q) const{ if(q < 0 || p < q) return 0; return (fact[p] * inv[q] % mod * inv[p - q] % mod); } };
template<class itr> bool next_sequence(itr first, itr last, int max_bound){ itr now = last; while(now != first){ now--; (*now)++; if((*now) == max_bound){ (*now) = 0; }else{ return true; } } return false; }

int main(){
    int N;
    cin >> N;
    if(N <= 2){
        cout << "No" << endl;
        return 0;
    }
    if(N % 4 == 3){
        cout << "Yes" << endl;
        for(int i = 1; i < 2 * N; i++){
            cout << i << " " << i + 1 << endl;
        }
        return 0;
    }
    int over = (N + 1) / 4 * 4 - 1;
    if(N % 4 == 2){
        cout << "Yes" << endl;
        for(int i = 4; i < over; i++){
            cout << i << " " << i + 1 << endl;
            cout << N + i << " " << N + i + 1 << endl;
        }
        int A = over + 1, B = over + 2, C = over + 3;
        cout << N + C << " " << 2 << endl;
        cout << 3 << " " << 2 << endl;
        cout << 2 << " " << A << endl;
        cout << A << " " << 1 << endl;
        cout << 1 << " " << N + B << endl;
        cout << A << " " << B << endl;
        cout << B << " " << N + 1 << endl;
        cout << B << " " << N + 3 << endl;
        cout << A << " " << C << endl;
        cout << C << " " << N + 2 << endl;
        cout << N + 2 << " " << N + A << endl;
        if(over > 4){
            cout << over << " " << N + 4 << endl;
            cout << over << " " << 1 << endl;
        }
        return 0;
    }
    if(N % 4 == 1){
        cout << "Yes" << endl;
        for(int i = 1; i < over; i++){
            cout << i << " " << i + 1 << endl;
            cout << N + i << " " << N + i + 1 << endl;
        }
        cout << over << " " << N + 1 << endl;
        int A = over + 1, B = over + 2;
        cout << A << " " << B << endl;
        cout << B << " " << 1 << endl;
        cout << 1 << " " << N + A << endl;
        cout << N + A << " " << N + B << endl;
        return 0;
    }
    if(N % 4 == 0){
        if(bitcount(N) == 1){
            cout << "No" << endl;
            return 0;
        }
        cout << "Yes" << endl;
        for(int i = 1; i < over; i++){
            cout << i << " " << i + 1 << endl;
            cout << N + i << " " << N + i + 1 << endl;
        }
        cout << over << " " << N + 1 << endl;
        int mostbit = 0;
        for(int i = 20; i >= 0; i--){
            if((N >> i) & 1){
                mostbit = i;
                break;
            }
        }
        cout << (1 << mostbit) << " " << N << endl;
        cout << N - (1 << mostbit) + 1 << " " << N * 2 << endl;
        return 0;
    }
}
