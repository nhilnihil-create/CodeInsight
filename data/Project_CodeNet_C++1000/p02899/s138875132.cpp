#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
using ll = long long;
using namespace std;
int main(){
    int n;cin>>n;
    vector<int> a(n);
    rep(i,n){
        int x;
        cin>>x;
        x--;
        a[x]=i+1;
    }
    vector<int> b(n);
    rep(i,n){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}