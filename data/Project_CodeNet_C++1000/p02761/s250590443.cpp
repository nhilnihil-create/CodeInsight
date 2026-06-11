#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(n,-1);
    int ans=0;
    for(int i = 0; i < m; i++) {
        int s,c; cin >> s >> c;
        if(a[s-1]==-1) a[s-1]=c;
        else{
            if(a[s-1]!=c) {
                cout << -1 << endl;
                return 0;
            }
        }
        if(n!=1 && a[0]==0){
            cout << -1 << endl;
            return 0;
        }
    }
    if(a[0]==-1) {
        if(n==1) a[0]=0;
        else a[0]=1;
    }
    for(int i = 1; i < n; i++) {
        if(a[i]==-1) a[i]=0;
    }
    for(int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;


    return 0;
}