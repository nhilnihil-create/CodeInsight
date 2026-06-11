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
    if(n<10)cout<<n<<endl;
    else if(n<100)cout<<9<<endl;
    else if(n<1000)cout<<n-90<<endl;
    else if(n<10000)cout<<909<<endl;
    else if(n<100000)cout<<n-9090<<endl;
    else cout<<90909<<endl;

    return 0;
}