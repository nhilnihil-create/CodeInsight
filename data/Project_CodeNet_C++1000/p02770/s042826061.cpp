#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long int ll;
const int K_MAX = 5002;
int d[K_MAX];
int k, q;

int main(){
    cin >> k >> q;
    for(int i = 0; i < k; i++){
        cin >> d[i];
    }

    vector<ll> ANS;
    for(int j  = 0; j < q; j++){
        ll n, x, m;
        cin >> n >> x >> m;
        x %= m;
        ll zero = 0;
        ll total = x;
        ll cyct = 0;
        ll cycz = 0;
        ll p = (n-2) / k;
        ll q = (n-2) % k;
        for(int i = 0; i < k; i++){
            int dm = d[i] % m;
            if (dm == 0){
                cycz++;
                if (i <= q)zero++;
            }
            cyct += dm;
            if (i <= q)total += dm;
        }
        zero += cycz * p;
        total += cyct * p;
        ll newans = n-1;
        newans -= zero;
        newans -= (total / m);
        ANS.push_back(newans);
    } 
    for(int j = 0; j < q; j++){
        cout << ANS[j] << endl;
    }
    return 0;
}