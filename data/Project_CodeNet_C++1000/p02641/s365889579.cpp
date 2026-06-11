#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
int main(){
    int x,n;
    cin>>x>>n;
    vector<int> p(300);
    rep(i,n){
        int a;
        cin>>a;
        p[a]=1;
    }
    int y=0;

    while (1){
        if(p[x-y]!=1){
            cout<<x-y<<endl;
            return 0;
        }
        else if(p[x+y]!=1){
            cout<<x+y<<endl;
            return 0;
        }
        y++;
    }
}