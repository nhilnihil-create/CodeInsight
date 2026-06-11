
#include<bits/stdc++.h>
using namespace std;
#define all(v)   v.begin(),v.end()
#define all(v) v.begin(),v.end()
#define meow ios::sync_with_stdio(0);cin.tie(0);

typedef long long int ll;
typedef unsigned long long int ull;

int main()
{
    meow;
    ll i,n,j,cnt=0,k;
    cin>>n;
    for(i=0;i<=n;i++){
        string str;
        ///str=stream(n);
         ///str=to_string(n);
       str=to_string(i);
        if(str.size()%2==1){
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
}
