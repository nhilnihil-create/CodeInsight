#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef long int li;

int main()
{
    IOS;
    //freopen("fr1.txt","r",stdin);
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool ok=true;
    if(n%2!=0)
        ok=false;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n/2+i])
            ok=false;
    }
    if(ok)
        cout<<"Yes"<<endl;
    else 
        cout<<"No"<<endl;
    return 0;
}


