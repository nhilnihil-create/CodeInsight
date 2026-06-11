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
    int p,q,r;
    cin>>p>>q>>r;
    int k=p+q;
    int l=q+r;
    int m=p+r;
    cout<<min(k,min(l,m))<<endl;

}










































