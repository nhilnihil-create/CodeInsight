#include<bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;
int n;
vector<int>vec;
void input();

void solve(){
    int cnt = 0;
    for(int i=0;i<n;i++){
        if((i+1)%2==1 && vec[i]%2==1)cnt++;
    }
    cout<<cnt<<"\n";
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
    cin>>n;
    for(int i=0;i<n;i++){
        int  a;
        cin>>a;
        vec.pb(a);
    }
}
