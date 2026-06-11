#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int left = 0, right = 1e9+1;
    while(right-left > 1){
        int tk = k;
        int mid = (right+left)/2;
        for(int i = 0; i < n; i++){
            if(a[i] > mid) tk -= a[i]/mid;
        }
        //cout << mid << " " << tk << endl;
        if(tk >= 0) right = mid;
        else left = mid;
    }

    cout << right << endl;

    return 0;
}