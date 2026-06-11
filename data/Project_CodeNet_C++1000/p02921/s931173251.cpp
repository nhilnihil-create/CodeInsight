/**Author:Sagor*/

#include<bits/stdc++.h>

using namespace std;
#define pri(n)          printf("%d\n",n)
#define prll(n)         printf("%lld\n",n)
#define prd(n)          printf("%lf\n",n)
#define scll(n)         scanf("%lld",&n)
#define sci(n)          scanf("%d",&n)
#define scd(n)          scanf("%lf",&n)
#define pi              acos(-1)
#define ll              long long
#define pb              push_back
#define vsort(v)        sort(v.begin(),v.end())
#define asort(n)        sort(ar,ar+n)
#define for1(i,n)       for(i=1;i<=n;i++)
#define for0(i,n)       for(i=0;i<n;i++)
#define mod             100000000


int main()
{
    /*ios_base::sync_with_stdio(false);
    cin.tie(NULL);/**Dont't use scanf of printf*/
    string st,str;
    cin>>st>>str;
    int i,cnt=0;
    for(i=0;i<3;i++){
        if(st[i]==str[i]) cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}
