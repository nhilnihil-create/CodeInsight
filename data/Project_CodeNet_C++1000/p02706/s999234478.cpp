#include<bits/stdc++.h> 
using namespace std;
using ll = long long;

#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);

int main() {
    fast_io;
    int n,m;
    cin>>n>>m;

    int total=0;
    while(m--) {
        int time;
        cin>>time;
        total+=time;
    }

    int ans=n-total;
    if(ans<0) {
        cout<<-1<<endl;
    }
    else {
        cout<<ans<<endl;
    }



}


