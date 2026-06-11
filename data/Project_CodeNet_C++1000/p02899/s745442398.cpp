#include "bits/stdc++.h"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, int> pos;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        pos[a]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<pos[i]+1<<" ";
    }
    cout<<endl;
}

