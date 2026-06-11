#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int n; cin>>n;
    
    map<int, int> a;
    for (int i=0; i<n; i++){
        int e; cin>>e;
        a[e]++;
    }

    for (auto i : a){
        if(i.second == 2){
            cout<<"NO"<<endl;
            return;
        }
    }
    
    cout<<"YES"<<endl;
}

int main(){
    solve();
    Bye;
}