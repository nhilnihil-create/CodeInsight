#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n , ans;
    cin>>n;
    ans=(n+1000-1) / 1000;
    
    // if(ans==1000) cout<<0<<endl;

    cout<<ans*1000-n<<endl;
    
    return 0;
    
    
}