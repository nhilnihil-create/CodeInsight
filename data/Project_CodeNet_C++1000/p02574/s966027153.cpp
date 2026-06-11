#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const int A = 1000001;

ll GCD(ll a, ll b){
    if(b == 0){
        return a;
    }else{
        return GCD(b, a % b);
    }
}
int main() {
    int n;
    cin >> n;
    ll ref = 0;
    ll sum = 0;
    vector<ll> a(n);
    vector<ll> c(A, 0);
    bool pairwise = true;

    
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        ref = GCD(a[i], ref);
        sum += a[i];
        c[a[i]]++;
    }
    for(int i = 2; i < A; i ++){
        int cnt = 0;
        for(int j = i; j < A; j += i){
            cnt += c[j];
        }
        if(cnt != 0 && cnt != 1){
            pairwise = false;
            break;
        }
    }
    
    
    if(pairwise == 1){
        cout << "pairwise coprime" << endl;
    }else if(ref == 1){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }
    return 0;
}
