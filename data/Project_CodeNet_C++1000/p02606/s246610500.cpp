#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
ll L,R,d;
void input();

void solve(){
    cout<<R/d - (L-1)/d<<"\n";
}

void Clear(){

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    input();
    solve();
    Clear();
}

void input(){
    cin>>L>>R>>d;
}
