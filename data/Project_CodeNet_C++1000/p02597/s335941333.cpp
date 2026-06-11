#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i;
    cin>>n;
    string s;
    cin>>s;
    int w=count(s.begin(),s.end(),'W'),r=n-w,wc=0;
    for(i=0;i<n;i++)
    {
        int c=0;
        if(s[i]=='W')
        {
            for(int j=n-1;j>=i;j--)
            {
                if(s[j]=='R')
                {
                    wc++;swap(s[i],s[j]);c=1;break;
                }

            }
            if(c==0)
                break;
        }
    }
    cout<<min(w,min(r,wc));

}

