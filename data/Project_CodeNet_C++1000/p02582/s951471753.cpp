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
using namespace std;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int ans = 0;
    char c;
    int temp = 0;
    for(int i=0; i<3; ++i){
        cin>>c;
        if(c=='R'){
            temp++;
            ans = max(ans,temp);
        }
        else
            temp = 0;
    }
    cout<<ans<<endl;
    return 0;
}
