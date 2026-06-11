#include<bits/stdc++.h>
//#include<iostream>
//#include<vector>
//#include<algorithm>
using namespace std;
int main()
{


        int n,c=0;
        string s;
        cin>>n;
        cin>>s;
        int i=0;
        while(i<s.length()-2)
        {
            if((s[i]=='A')&&(s[i+1]=='B')&&(s[i+2]=='C'))
            {
                c++;
                i=i+3;
            }
            else
            {
                i++;
            }
        }
        cout<<c<<endl;

    return 0;
}
