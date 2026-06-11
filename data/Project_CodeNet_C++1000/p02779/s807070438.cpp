#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int n; cin>>n;
    
    set<int> a;
    bool exists = false;
    for (int i=0; i<n; i++){
        int e; cin>>e;
        if(a.count(e) == 1) exists = true;
        else a.insert(e);
    }
    cout<<(exists?"NO":"YES")<<endl;
}

int main(){
    solve();
    Bye;
}