#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p,c=0,i=0;
    vector<int>v;
    vector<int>v1;
    cin>>n;
    int t=n,x;
    while(t--)
    {
        cin>>x;
        v.push_back(x);
        v1.push_back(x);

    }
    sort(v1.begin(),v1.end());
    while(i<v.size())
    {
        if(v1[i]==v[i])
            c++;
        i++;
    }
    //cout<<c<<endl;
    if(c>=n-2)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;
}

