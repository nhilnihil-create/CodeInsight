#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int k;
    cin>>k;
    vector<int>func(k+1);
  for(int i=1;i<=k;i++)
   {

       for(int j=i;j<=k;j+=i)
        func[j]++;
   }
    unsigned long long ans=0;
    for(int i=1;i<=k;i++)
        ans+=i*(1ll)*func[i];
    cout<<ans<<endl;
    return 0;
}
