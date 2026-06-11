#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,k,flag;
    string s;
    while(~scanf("%d",&n))
    {
        flag = 1;
        cin >> s;
        if(n%2)cout<<"No"<<endl;
        else
        {
            for(i=0,j=n/2;i<n/2;i++,j++)
            {
                if(s[i]!=s[j]) flag = 0;
            }
            if(flag)cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
    return 0;
}