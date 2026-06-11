#include<bits/stdc++.h>
using namespace std;
#define ios ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long
#define endl '\n'
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
bool sortbysec(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
int main()
{
    ios;
    int n;
    cin>>n;
    int a[n];
    set<int,greater<int> >s;
    map<int,int>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        m[a[i]]++;
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(m[a[i]]==1)
        {
            s.erase(a[i]);
             set<int,greater<int> >::iterator it;
             it=s.begin();
            cout<<*it<<endl;
            s.insert(a[i]);
        }
        else
        {
             set<int,greater<int> >::iterator it;
             it=s.begin();
             cout<<*it<<endl;
        }


    }



}























































