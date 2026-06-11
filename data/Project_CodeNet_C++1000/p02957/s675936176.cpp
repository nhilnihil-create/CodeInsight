#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
          ll a,b;
          cin>>a>>b;
          for(ll i=0;i<max(a,b);i++)
                    if(abs(a-i)==abs(b-i)){
                    cout<<i<<endl;return 0;}
                    cout<<"IMPOSSIBLE"<<endl;


}
