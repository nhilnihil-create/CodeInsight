#include<bits/stdc++.h>
#include<algorithm>

using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef long int li;

int main()
{
    IOS;
    //freopen("fr.txt","r",stdin);
    int m,n;
    cin>>m>>n;
    int a=min(m,n);
    int b=max(m,n);
    for(int i=1;i<=b;i++){
        cout<<a;
    }
    cout<<endl;
    return 0;
}