#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
const ll  big =2e5+5;
pair <int,int> p[1005];
ll a[1005],b[1005];

int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
ll s,w;
cin>>s>>w;
if(w>=s)cout<<"unsafe";
else cout<<"safe";

    return 0;
}
