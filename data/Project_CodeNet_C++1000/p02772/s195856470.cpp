#include <bits/stdc++.h>
#include <vector>
#include <map>
#define ll long long
#define h   "\n"
#define ios
using namespace std;

int main()
{

  int n,ev=0,ans=0;

  cin>>n;

  vector <int> v(n);

  for(int i=0;i<n;i++)
  {
    cin>>v[i];
    if(v[i]%2==0)
        ev++;
  }

  for(int i=0;i<n;i++)
    {
        if(v[i]%2==0)
        {
            if(v[i]%3!=0 && v[i]%5!=0)
             {
                cout<<"DENIED"<<h;
                break;
             }
            else
                ans++;
        }
    }

    if(ans==ev)
        cout<<"APPROVED"<<h;

    return 0;
}
