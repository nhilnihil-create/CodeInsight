#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int>plus(n),minus(n);

    for(int i=0;i<n;i++){
        int x,y;
        cin >>x >> y;
        plus[i]=x+y;
        minus[i]=x-y;
    }

    sort(plus.begin(),plus.end());
    sort(minus.begin(),minus.end());
    cout<<max(plus[n-1]-plus[0],minus[n-1]-minus[0])<<endl;
}


