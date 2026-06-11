#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    int A,B,C,ans;

    cin>>A>>B>>C;

    ans=C-(A-B);
    if(ans<0)ans=0;

    cout<<ans<<endl;


    return 0;
}
