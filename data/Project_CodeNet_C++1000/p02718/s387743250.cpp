#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    double sum=0;
    for(uint i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(float(v[i])>=sum/(4*m))
        {
            count++;
            if(count>=m)
            {
                cout<<"Yes"<<endl;
                return 0;
            }
        }
        
    }
   cout<<"No"<<endl;
	return 0;
}
