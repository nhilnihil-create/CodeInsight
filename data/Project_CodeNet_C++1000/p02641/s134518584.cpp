#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<set>

using namespace std;

int search(set<int> btr,int low,int high)
{
    if(btr.count(low)==0)
    {
        return low;
    }
    else if(btr.count(high)==0)
    {
        return high;
    }
    else if((btr.count(high)==1) && (btr.count(low)==1))
    {
        return search(btr,low-1,high+1);
    }
}

int main()
{
    int x,n;
    set<int> vexas;
    int input;

    cin>>x>>n;

    for(int i=0;i<n;i++)
    {
        cin>>input;
        vexas.insert(input);
    }

    int ans; 

    if(n==0)
    {
        cout<<x<<endl;
    }
    else
    {
        ans = search(vexas,x,x);
        cout<<ans<<endl;
    }
    
    vexas.clear();
    return 0;
}