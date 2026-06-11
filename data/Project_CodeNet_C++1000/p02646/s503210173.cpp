#include<bits/stdc++.h>

using namespace std;

void input();
string s;
long long  a;
long long  b;
long long v,w,t;
void solve(){
    if( v<=w){
        cout<<"NO\n";
    }
    else{
        long long d = (v-w)*t;
      	
        if(abs(a-b)<=d){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
}

void input(){
    cin>>a>>v>>b>>w;
    cin>>t;
}
