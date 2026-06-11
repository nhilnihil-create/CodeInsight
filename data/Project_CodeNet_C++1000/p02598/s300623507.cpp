#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()

using ll = long long;
using P = pair<int,int>;
using mp =  map<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main(void){

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int amax = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        amax = max(a[i], amax);
    }

    int left = 0, right = amax + 1, mid = 0;
    while (left + 1 < right) {
        mid = (left + right) / 2;

        int cnt = 0;
        for(int i = 0; i < n; ++i){
            cnt += (a[i] - 1) / mid;
        }

        if(cnt <= k){
            right = mid;
        }else{
            left = mid;
        }
    }

    cout << right << "\n";


    return 0;
}
