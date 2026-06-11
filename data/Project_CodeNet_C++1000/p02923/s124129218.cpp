#include<bits/stdc++.h>

#define CodeTyper main
#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int n; cin>>n;
    int h[n];
    for (int i=0; i<n; i++){
        cin>>h[i];
    }

    int cont = 0;
    int maxi = 0;
    for (int i=0; i<n-1; i++){
        if(h[i]<h[i+1])
            cont = 0;
        else cont++;
        maxi = max(maxi, cont);
    }
    cout<<maxi<<endl;
}

int CodeTyper(){
    solve();
    Bye;
}