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
    string s1,s2,s;
    int n;
    cin>>n;
    cin>>s1>>s2;
    for(int i=0;i<n;i++){
        s=s+s1[i];
        s=s+s2[i];
    }
    cout<<s<<endl;
    
    
    return 0;
}
