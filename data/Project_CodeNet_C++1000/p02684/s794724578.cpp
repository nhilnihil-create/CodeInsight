#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    // cout << fixed << setprecision(10) << flush;

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
        a[i]--;
    }

    vector<int> dis_from_one(n, -1);
    dis_from_one[0] = 0;
    int d = 1;
    int i = a[0];
    while(dis_from_one[i] == -1){
        dis_from_one[i] = d;
        if(k == d){
            cout << i+1 << endl;
            return 0;
        }
        d++;
        i = a[i];
    }


    int rem = (k-dis_from_one[i]) % (d - dis_from_one[i]);
    for(int ii=0; ii<rem; ii++){
        i = a[i];
    }
    cout << i+1 << endl;

    return 0;
}