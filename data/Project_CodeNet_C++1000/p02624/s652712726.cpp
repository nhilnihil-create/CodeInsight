#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
const ll  big =1e7+2;

ll a[big];

int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

ll n;
cin>>n;
for(int i=1;i<=n;++i){
    for(int j=i;j<=n;j+=i){
        a[j]++;
    }
}
ll sum=0;
for(int i=1;i<=n;++i)
  sum+=i*a[i];

cout<<sum;
    return 0;
}