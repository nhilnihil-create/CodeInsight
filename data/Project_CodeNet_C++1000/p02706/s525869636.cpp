#include<bits/stdc++.h>
using namespace std;
int main()
{
    int lim,num,sum;
    vector<int>v1;
    while(cin>>num>>lim)
    {
        sum=0;
        for(int i=0;i<lim;i++)
        {
            int temp;
            cin>>temp;
            v1.push_back(temp);
            sum+=v1[i];
        }
        if(num>=sum)
        {
        cout<<(num-sum)<<endl;
        }
        else 
        {
        cout<<"-1"<<endl;
        }
        break;
    }
    
}
