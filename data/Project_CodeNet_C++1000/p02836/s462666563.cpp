#include<bits/stdc++.h>
using namespace std;
int main()
{


        string s;
        cin>>s;
        int m=s.length(),c=0,i,j;
        for(i=0;i<m;i++)
        {
            if(s[i]!=s[m -1-i])
            {
                c++;
            }

        }
        cout<<c/2<<endl;
}
