#include<bits/stdc++.h>
#define test int t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
using namespace std;
 
int main()
{
  long long a,b,c;
  cin>>a>>b;
  if(a==1&&b==2||a==2&&b==1)
    cout<<3<<endl;
    else if(a==2&&b==3||a==3&&b==2)
    cout<<1<<endl;
  else if(a==1&&b==3||a==3&&b==1)
    cout<<2<<endl;
}