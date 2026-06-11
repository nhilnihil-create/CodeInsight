#include<bits/stdc++.h>
using namespace std;
vector<int> l1,l2;
int main()
{
    int n,c,k;
    string s;
    cin>>n>>k>>c;
    cin>>s;
    int last=-1e9;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='o'&&last+c<i)
        {
            l1.push_back(i);
            last=i;
        }
        if(l1.size()==k) break;
    }
    int stock=1e9;
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='o'&&stock>=c)
        {
            stock=0;
            l2.push_back(i);
        }
        else stock++;
        if(l2.size()==k) break;
    }
    reverse(l2.begin(),l2.end());
    for(int i=0;i<k;i++) if(l1[i]==l2[i]) cout<<l1[i]+1<<endl;
}