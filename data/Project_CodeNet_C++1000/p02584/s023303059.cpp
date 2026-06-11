#include<iostream>

#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<set>
#include<queue>


using namespace std;
#define int long long



signed main()
{
      int n,k,d;
      cin>>n>>k>>d;
      n=abs(n);
      int q=n/d;
      int r=n%d;
      if(k==q)
        cout<<r<<endl;
      else if(k>q)
        {
            if((q%2)^(k%2))
                cout<<d-r<<endl;
            else
                cout<<r<<endl;
        }
      else
        cout<<n-k*d<<endl;
      return 0;

}
