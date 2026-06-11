#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int p[n];
    rep(i,n){
        cin>>p[i];
    }
    int cnt=0;
    for(int i=1;i<n-1;i++){
        if((p[i]>p[i-1]&&p[i]<p[i+1])||(p[i]<p[i-1]&&p[i]>p[i+1]))cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}