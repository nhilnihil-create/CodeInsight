#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(){
    int N, L;
    cin >> N >> L;
    int sum = 0;
    int mindiff = 500000;
    int d;
    for (int i = 0; i < N; i++) {
        sum += L + i;
        int diff = abs(L + i);
        if (diff < mindiff){
            mindiff = diff;
            d = L + i;
        }
    }
    cout << sum - d << endl;
}