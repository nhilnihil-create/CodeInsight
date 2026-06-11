#include<bits/stdc++.h>

#define Bye return 0
#define ll long long

using namespace std;

void solve(){
    int a, b; cin>>a>>b;
    int c = 1;
    while(c<=1009){
        int x = (int) c*0.08;
        int y = (int) c*0.1;

        if(x==a && y==b){
            cout<<c<<endl;
            return;
        }
        c++;
    }
    cout<<"-1"<<endl;
}

int main(){
    solve();
    Bye;
}