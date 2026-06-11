#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define db double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ino freopen("in.txt", "r", stdin);freopen("out.txt", "w", stdout);

#define fr(i,n) for(i=0;i<n;i++)
#define frs(i,a,n) for(i=a;i<n;i++)
#define frv(i,n) for(i=n-1;i>=0;i--)

#define ne cout<<"\n";
#define cas(i) cout<<"Case #"<<i<<": "

#define vi vector <int>
#define vpi vector <pair <int,int> >
#define vpin(v,a,b) v.push_back(make_pair(a,b))
#define vsort(v) sort(v.begin(),v.end());
#define all(v) ((v).begin()),((v).end())
#define sz(v) ((int)((v).size()))

#define todegree(rad) rad*(180.0/pi)
#define isnttriangle(a,b,c) (a+b<c||a+c<b||b+c<a)
#define pi acos(-1)
#define siz 1000


int main()
{
    int N,a,b,c;
    db k,m,num;
    cin>>N;
    num=N*1.0;
    bool ok=false;
    a=floor(num/1.08);
    if(floor(a*1.08)==N)
    {
        ok=true;
        cout<<a<<"\n";
    }
    a=ceil(num/1.08);
    if(floor(a*1.08)==N)
    {
        if(!ok)
        cout<<a<<"\n";
        ok=true;
    }
    if(!ok) cout<<":(\n";

    return 0;
}
