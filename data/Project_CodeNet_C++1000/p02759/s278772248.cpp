
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int n;
    cin >> n;
    if(n%2==0){
        cout << n/2 << endl;
    }
    else{
        cout << n/2 +1 << endl;
    }
}