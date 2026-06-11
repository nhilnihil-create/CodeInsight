#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> d;
vector<vector<int>> a;

void input()
{
    cin>>n>>k;
    d.resize(k);
    a.resize(k,vector<int>());
    for(int i =0;i<k;i++){
        cin>>d[i];
        a[i].resize(d[i]);
        for(int j=0;j<d[i];j++){
            cin>>a[i][j];
        }
    }
}
void solve()
{
    int ans=0;
    for(int i=1;i<=n;i++){
        bool have = false;
        for(auto v: a){
            for(auto p:v){
                if(p == i){
                    have = true;
                }
            }
        }
        if(!have){
            ans++;
    }
    }
    cout<<ans<<endl;
    }
int main()
{
    input();
    solve();
    return 0;
}
