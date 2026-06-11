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
long long a[105];
int ans;
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);
    int n;
    cin>>n;
    for(int i=1; i<=n; ++i){
        cin>>a[i];
    }
    for(int i=1; i<=n; ++i){
        for(int j=i+1; j<=n&&i!=j; j++){
            for(int k=j+1; k<=n&&i!=k&&j!=k&&i!=j; k++){
                if(a[i]==a[j]||a[i]==a[k]||a[j]==a[k])
                    continue;
                if(abs(a[i]-a[j])<a[k]&&abs(a[i]-a[k])<a[j]&&abs(a[j]-a[k])<a[i]){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
