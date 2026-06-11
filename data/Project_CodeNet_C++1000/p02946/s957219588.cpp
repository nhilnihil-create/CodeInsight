
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main(){
    int k, x;
    cin >> k >> x;
    for(int i=x-k+1; i<=x+k-1; i++){
        if(i<-1000000 || 1000000<i){
            continue;
        }
        else cout << i << " ";
    }
    cout << endl;

}