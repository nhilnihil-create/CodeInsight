#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,d;
    cin>>n>>d;
    for(int i=0;;i++){
        if(n<=0){
            cout<<i<<endl;
            return 0;
        }
        n=n-2*d-1;
    }
}