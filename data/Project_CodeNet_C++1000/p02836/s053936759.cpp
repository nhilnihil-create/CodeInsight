#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s.size()%2)
    { int ans=0;
        int low=((s.size())/2)-1;
        int high=((s.size())/2)+1;
        while(low>=0 && high<=(s.size()-1))
        {
            if(s[low]!=s[high])
            {
                ans++;
                
            }
            low--;high++;
        }
        cout<<ans;
    }
    else
    {int ans=0;
        int low=((s.size())/2)-1;
        int high=((s.size())/2);
        while(low>=0 && high<=(s.size()-1))
        {
            if(s[low]!=s[high])
            {
                ans++;
            
            }
            low--;high++;
        }
        cout<<ans;
        
    }
}