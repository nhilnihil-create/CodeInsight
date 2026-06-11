#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
#define INF (1 << 30)
using namespace std;

int primeNumber(int n){
    if(n == 2) return 1;
    else if(n < 2) return 0;
    else{
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0) return 0;
        }
        return 1;
    }
}
int main(){
    int sum = 0;
    for(int n; cin >> n;){
        sum+=primeNumber(n);
    }
    cout << sum << endl;
}