#include<iostream>
#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    string compare2;
    string given;

    cin>>compare2>>given;
    
    int len1 = compare2.size();
    int len2 = given.size();
    
    int cost = 0;
    int mincost = INT_MAX;

    if(len1==len2)
    {
        if(compare2.compare(given)==0)
        {
            cout<<0<<endl;
        }
        else
        {
            for(int i=0;i<len2;i++)
            {
                if(compare2.at(i)!=given.at(i))
                {
                    cost++;
                }
            }
            cout<<cost<<endl;
        }
        
    }
    else
    {
        for(int i=0;i<(len1 - len2);i++)
        {
            cost=0;
            for(int j=i;j<(i + len2);j++)
            {
                if(given.at(j-i)!=compare2.at(j))
                {
                    cost++;
                }
        
            }  
            if(mincost>=cost)
            {
                mincost=cost;
            }
        }
        cout<<mincost<<endl;    
    }
    return 0;
}