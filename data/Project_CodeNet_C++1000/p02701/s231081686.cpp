#include <iostream>
#include <bits/stdc++.h>
using namespace std;
set<string>s;
string a[1000009];
int main()
{
    int n;
    string z;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        z=a[i];
        s.insert(z);
    }
      cout<<s.size();



    return 0;
}
