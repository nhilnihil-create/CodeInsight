#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200003],last;
ll ans;

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    last=a[1];
    
	for(int i=2;i<=n;i++)
	{
        if(last>a[i]) ans+=last-a[i];
        else last=a[i];
    }
    cout<<ans<<endl;
    return 0;
}
