#include<bits/stdc++.h>
using namespace std;

vector<int>v[200004];

int main()
{
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        v[x].push_back(i);
    }
    int cnt=0,prev=-1;
    for(int i=1;i<=200000;i++)
    {
        if(v[i].size()==0) break;
        sort(v[i].begin(),v[i].end());
        int X=upper_bound(v[i].begin(),v[i].end(),prev)-v[i].begin();
        //cout<<"X : "<<v[i][X]<<endl;
        if(X>=v[i].size()) break;
        int num=v[i][X];
        //cout<<
        if(num>prev) { prev=num; cnt++; }
        else break;
    }
    if(prev==-1) cout<<-1<<endl;
    else cout<<n-cnt<<endl;
}
