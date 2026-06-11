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
   string s;
   int n;
   cin>>n;
   cin>>s;
   int c=0;
   for(int i=0;i<n;i++){
    if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C')
        c++;
   }
   cout<<c<<endl;

    return 0;
}