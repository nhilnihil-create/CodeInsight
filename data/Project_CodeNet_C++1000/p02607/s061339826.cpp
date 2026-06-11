#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   // your code goes here

    int n,c=0;
    int a[105];
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (i%2!=0)
        {
            if (a[i]%2!=0)c++;
        }
    }

  cout<<c;


}
