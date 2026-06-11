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

int main()
{
    int l,r,d;
    cin>>l>>r>>d;
    int ans = 0;
    for(int i=l; i<=r; ++i){
        if(i%d==0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
