#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep2(i, j, n) for (int i = j; i <= (int)(n); i++)
// greedy
int main(void){
    ll N;
    cin >> N;
    ll A[87];
    ll money = 1000;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N-1 ;i++){
        ll stock = 0;
        if(A[i] < A[i+1]){
            stock = money / A[i];
        }
        money += (A[i+1] - A[i]) * stock;
    }
    cout << money << endl;
}