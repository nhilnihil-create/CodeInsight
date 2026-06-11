#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <set>
#include <algorithm>
#include <iomanip>

typedef long long ll;
const ll MOD = 1e9 + 7;
const long long INF = 1LL<<60;
const double PI=3.14159265358979323846;
const int NMAX=1000001;
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<ll> prime(NMAX), cnt(NMAX, 0);
    for(int i = 0; i < NMAX; i++){
        prime[i] = i;
    }
    int p = 2;
    while(p*p <= NMAX){
        if(prime[p] != p){
            p++;
            continue;
        }
        for(int i = p; i < NMAX; i += p){
            prime[i] = p;
        }
        p++;
    }

    bool pairwise = true;
    bool setwise = true;

    for(int i = 0; i < n; i++){
        int tmp = a[i];
        while(prime[tmp] != tmp){
            int sis = prime[tmp];
            cnt[sis]++;
            while(tmp != 1 && tmp%sis == 0) tmp /= sis;
        }
        cnt[prime[tmp]]++;
    }

    for(int i = 2; i < NMAX; i++){
        if(cnt[i] == n){
            pairwise = false;
            setwise = false;
            break;
        } else if(cnt[i] > 1){
            pairwise = false;
        }
    }

    if(pairwise){
        cout << "pairwise coprime" << endl;
    } else if(setwise){
        cout << "setwise coprime" << endl;
    } else {
        cout << "not coprime" << endl;
    }

    return 0;
}