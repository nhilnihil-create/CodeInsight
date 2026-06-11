#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {

    int n;int i;int abbccount=0;
    string s;
    cin>>n;
      if(n<3)
        {
            cout<<0<<endl;
            exit(0);
        }
    cin>>s;

    for(i=0;i<n;i++)
    {
        if (s[i]=='A' && s[i+1]=='B' && s[i+2]=='C')
        {
            abbccount=abbccount+1;
        }
        else
        {
            continue;
        }

    }
    cout<<abbccount<<endl;


}
