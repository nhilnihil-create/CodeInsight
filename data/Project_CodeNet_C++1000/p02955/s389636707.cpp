#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){

    int n, k, sm = 0;
    cin >> n >> k;

    vector<int> arr(n);

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sm += arr[i];
    }

    vector<int> fct;
    for(int i = 1; i <= sqrt(sm); i++)
        if( sm%i == 0 ){
            fct.push_back(i);
            fct.push_back(sm/i);
        }

    int ans = 1, tot, used;
    for(int f : fct){
        tot = 0;
        vector<int> tmp;
        for(int i = 0; i < n; i++){
            tmp.push_back(arr[i]%f);
            tot += (f - arr[i]%f);
        }
        sort(tmp.begin(), tmp.end());
        used = 0;
        for(int i = 0; i < tmp.size(); i++){
            used += tmp[i];
            tot -= (f - tmp[i]);
            if( used == tot && used <= k ){
                ans = max(ans, f);
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}