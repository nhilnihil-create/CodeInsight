#include<bits/stdc++.h>
using namespace std;
using ll = long long int;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)


int main()
{
    IOS;
   //freopen("inputfile.txt","r",stdin);
  set <string>s;
  int n;cin>>n;
  while(n--)
  {
      string c;cin>>c;
      s.insert(c);
  }
  cout<<s.size()<<endl;
    return 0;
}
//<!...........ALHAMDULILLAH.............!!>>

