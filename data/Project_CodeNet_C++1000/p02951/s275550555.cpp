#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 100000000
const int MOD = 1000000007;


int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int x = a-b;
    if(c-x>=0)
    {
        cout<<c-x<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    
    return 0;
}