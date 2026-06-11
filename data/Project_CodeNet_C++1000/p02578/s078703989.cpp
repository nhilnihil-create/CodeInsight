#include<bits/stdc++.h>
using namespace std;

int main()
{
  long long int n;
  cin >> n;
  vector<long long int> v(n);
  for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

   long long  int stools = 0;
    
    for(int i = 1; i < n; i++)
        {
            if(v[i]<v[i-1])
                {
                    stools+= (v[i-1]-v[i]);
                    v[i]=v[i-1];
                }
        }
    cout<<stools;
    
  return 0;
}
