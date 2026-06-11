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
    int n,a[105];
    int ans = 0;
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    for(int i=1; i<=n; i+=2){
        if(a[i]%2==1)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}
