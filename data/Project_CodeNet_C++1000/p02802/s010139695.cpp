#include<bits/stdc++.h>

using namespace std;

int main()
{ 
    int n,m;
    cin>>n>>m;
    vector<bool> seen(n+1,false);
    vector<int> wrong(n+1,0);
    int rights = 0,wrongs = 0;
    for(int i = 0;i<m;i++)
    {
        int x;
        string s;
        cin>>x>>s;
        if(seen[x])
        {
            continue;
        }

        if(s == "WA")
        {
            wrong[x]++;
        }
        else if(s == "AC")
        {
            rights++;
            seen[x] = true;
        }
    }

    for(int i = 0;i<=n;i++)
    {
        if(seen[i])
        {
            wrongs += wrong[i];
        }
    }

    cout<<rights<<" "<<wrongs<<"\n";
    

    return 0;
}