#include<bits/stdc++.h>
using namespace std;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int k;  cin>>k;
string s;   cin>>s;
if (s.size()<=k)
{
    cout<<s<<endl;
    return 0;
}
else {
    for(int i=0;i<k;i++)
    {
      cout<<s[i];
    }

   cout<<"..."<<endl;
}

return 0;}
