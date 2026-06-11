#include <bits/stdc++.h>
#define ll long long
#define ii pair <int, int>
#define dl pair <ll, ll>
#define vi vector <int>
#define vl vector <ll>
#define vii vector <ii>
#define REP(a, b) for (int i = a; i < b; i++)
#define REP2(a, b) for (int j = a; j < b; j++)
#define REPS(a, b, c) for (int i = a; iQ < b; i += c)
#define tam 1000001

using namespace std;

int n;
int arr[tam];
bitset <tam> primo;
int e[tam];

bool sieve() {
    primo.set();
    primo[0] = primo[1] = 0;
    int cont;
    for (int i = 2; i < tam; i++) {
        if (primo[i]) {
            cont = 0;
            cont += e[i];
            for (int j = i * 2; j < tam; j += i) {
                primo[j] = 0;
                cont += e[j];
            }
            if (cont > 1) return false;
        }
    }
    return true;
}

int gcd(int a, int b) {return b == 0 ? a : gcd(b, a % b);}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    REP(0, n) {
        cin >> arr[i];
        e[arr[i]]++;
    }
    if (sieve()) cout << "pairwise ";
    else {
        int ac = arr[0];
        REP(1, n) {
            ac = gcd(ac, arr[i]);
        }
        if (ac == 1) cout << "setwise ";
        else cout << "not ";
    }
    cout << "coprime\n";
    return 0;
}
