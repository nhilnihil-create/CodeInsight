#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //I don't care about anybody, and fuck ratings! I'll go to google!
    int n, k, q, x; cin>>n>>k>>q;
    vector<int> a(n, k-q);
    for(int i = 0 ; i<q; i++){
        cin>>x;
        x--;
        a[x]++;
    }
    for(int p : a){
        if(p>0) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0; 
}
