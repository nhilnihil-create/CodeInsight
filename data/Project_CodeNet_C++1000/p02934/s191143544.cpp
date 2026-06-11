#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    float c=0.0;
    vector<float> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(int i=0;i<n;i++)
    {
        c+=(1.0/(v[i]*1.0));
    }
    cout<<(1/c*1.0)<<endl;
    return 0;
}
