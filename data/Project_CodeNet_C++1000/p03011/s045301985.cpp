#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    /////////////////////
    // Write code below /
    /////////////////////
    int P,Q,R,M;

    cin>>P>>Q>>R;

    cout<<P+Q+R-max({P,Q,R})<<endl;

    return 0;
}
