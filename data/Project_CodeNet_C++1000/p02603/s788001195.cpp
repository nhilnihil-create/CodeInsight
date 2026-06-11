#include "bits/stdc++.h"
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin >> arr[i];
    vector<int> smn,smx;
    smn.push_back(0);
    smx.push_back(0);
    ll tot=1000;
    int i=0;
    while(true) {
        if(i==n-1)
            break;
        while(i!=n-1 && arr[i]>arr[i+1])
            i++;
        ll mn=arr[i];
        while(i!=n-1 && arr[i]<=arr[i+1])
            i++;
        ll mx=arr[i];
        ll cnt=tot/mn;
        tot-=cnt*mn;
        tot+=cnt*mx;
    }
    cout << tot;

    return 0;
}
