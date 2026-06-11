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

int n,d;
int ans = 0;
int main()
{
    cin>>n>>d;
    for(int i=0; i<n; ++i){
        ll x,y;
        cin>>x>>y;
        if(sqrt(x*x+y*y)<=d){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
