#include<bits/stdc++.h>
#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int n; cin>>n;
    set<string> item;
    while(n--){
        string str; cin>>str;
        item.insert(str);
    }
    cout<<item.size()<<endl;
}

int main(){
    solve();
    Bye;
}