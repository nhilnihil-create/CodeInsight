#include <iostream>
using namespace std;
const int lim = 1e6 + 2;
int a[lim],lp[lim],pr[lim],avail[lim];
int n , cnt = 0;
int _gcd(int a,int b){
    if (b == 0) return a;
    return _gcd(b , a % b);
}
void sieve(){
    for (int i = 2; i <= lim; i++){
        if (lp[i] == 0) lp[i] = pr[++cnt] = i;
        int j = 1;
        while (j <= cnt && pr[j] * i <= lim && pr[j] <= lp[i]){
            lp[pr[j] * i] = pr[j];
            j++;
        }
    }
}
bool pairwise_coprime(){
    for (int i = 1; i <= n; i++){
        int save = a[i];
        while (save > 1){
            int temp = lp[save];
            if (avail[temp] > 0) return false;
            while (save % temp == 0) save /= temp;
            avail[temp]++;
        }
    }
    return true;
}
bool setwise_coprime(){
    int temp = a[1];
    for (int i = 2; i <= n; i++) temp = _gcd(temp,a[i]);
    if (temp == 1) return true; else return false;
}
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fill(avail + 1,avail + lim,0);
    fill(lp + 1,lp + lim,0);
    sieve();
    if (pairwise_coprime() == true){
        cout << "pairwise coprime";
        return 0;
    }
    if (setwise_coprime() == true){
        cout << "setwise coprime";
        return 0;
    }
    cout << "not coprime";
    return 0;
}