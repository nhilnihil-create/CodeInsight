#include <bits/stdc++.h>
using namespace std;
typedef long long       ll;
const ll  big =2e5+5;
pair <int,int> p[1005];
ll a[1005],b[1005];

int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
ll a,b,c,d;
cin>>a>>b>>c>>d;
ll k=0;
bool p=true;
while(p){
if(k%2==0){
    c-=b;
    k++;
    if(c<=0){cout<<"Yes";return 0;}
}
else{
     a-=d;
    k++;
    if(a<=0){cout<<"No";return 0;}
}}

    return 0;
}