#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int n, k;
int a[200005];

bool check(int key) {
    int cnt = 0;
    for(int i = 0; i < n; ++i){
        cnt += (a[i] - 1) / key;
    }

    if (cnt <= k){
        return true;
    }else{
        return false;
    }
}

int main(void){

    cin >> n >> k;

    int amax = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        amax = max(a[i], amax);
    }

    int ng = 0, ok = amax, mid;
    while (abs(ok - ng) > 1) {
        mid = (ok + ng) / 2;

        if (check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << "\n";

    return 0;
}
