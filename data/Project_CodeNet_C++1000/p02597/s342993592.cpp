#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<time.h>
#include<vector>
#define ll long long
using namespace std;

int w[200005],r;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin>>n;

    for(int i=1; i<=n; ++i){
        char c;
        cin>>c;
        if(c=='W'){
            w[i] = w[i-1]+1;
        }
        else if(c=='R'){
            r++;
            w[i] = w[i-1];
        }
    }
    int ans = w[r];
    cout<<ans<<endl;
    return 0;
}
