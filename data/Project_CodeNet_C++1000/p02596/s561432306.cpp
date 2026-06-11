#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<string,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int k, a[1000005];
    cin >> k;

    a[0] = 7 % k;
    for(int i = 1; i < k; ++i){
        a[i] = (a[i-1] * 10 + 7) % k;
    }

    for(int i = 0; i < k; ++i){
        if(a[i] == 0){
            cout << i+1 << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";

    return 0;
}
