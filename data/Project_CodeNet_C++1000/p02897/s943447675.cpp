
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int my_ceil(int a, int b){
    return (a+b-1)/b;
}

int main(){
    int n;
    cin >> n;
    cout << fixed << setprecision(10);
    cout << (double)my_ceil(n,2)/(double)n << endl;

}