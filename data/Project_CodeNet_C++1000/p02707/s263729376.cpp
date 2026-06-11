#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n+1);
    for (int i=0; i<n-1; i++){
        int e; cin>>e;
        a[e-1]++;
    }

    for (int i=0; i<n; i++)
        cout<<a[i]<<endl;
}

int main(){
    solve();
    Bye;
}