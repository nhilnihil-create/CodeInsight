#include <iostream>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = 1; i <= (n); i++)
#define drep(i,n) for(int i = (n)-1; i >= 0; i--)
#define srep(i,s,t) for (int i = s; i < t; i++)
#define rng(a) a.begin(),a.end()
using ll = long long;

using namespace std;



int main() {
    int n,d;
    cin>>n>>d;
    int ans = 1;
    int p = d+1;
    while(p+d<n){
        p += 2*d+1;
        ans ++;
    }
    cout<<ans<<endl;

    return 0;
}
