#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    IOS;
    //freopen("inputfile.txt","r",stdin);
   ll n;cin>>n;
   string s;
   while(n!=0)
   {
       ll mod = n%26;
       //cout<<char(mod-97)<<endl;
       if(mod==0){s.push_back('z');n=(n/26)-1;}
       else {s.push_back(char(mod-1+97));n = n/26;}
       //cout<<n<<endl;
   }
   reverse(s.begin(),s.end());
    cout<<s<<endl;
   return 0;
}

