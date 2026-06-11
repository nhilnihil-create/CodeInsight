#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define ft first
#define sd second
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<long long,long long> pll;

int main() {
    fastIO;
    int n, l, aux, rta = 0;
    cin >> n >> l;
    vector<pii> data;
    for(int i = 1; i <= n; i++){
        aux = i + l - 1;
        rta += aux;
        if(aux < 0) data.pb({abs(aux),-1});
        else data.pb({aux, 1});
    }
    pii inicio;
    sort(data.begin(), data.end());
    inicio = data[0];
    rta -= inicio.ft * inicio.sd;
    cout << rta << endl;
    return 0;
}

