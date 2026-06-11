#include<bits/stdc++.h>
#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int x, y, a, b; cin>>x>>y;

    a = (4*x-y)/2;
    b = (y-2*x)/2;

    if(a>=0 && b>=0 && y%2 == 0 && y>=2*x && y<=4*x)
        cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

int main(){
    solve();
    Bye;
}