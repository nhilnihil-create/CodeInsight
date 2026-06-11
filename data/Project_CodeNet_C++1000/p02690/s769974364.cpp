#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long int lld;
#define sq(x) (x*x*x*x*x)
#define fr(i,m,n) for(i=m;i<n;i++)
#define vec vector<int>
#define sint set<int>
#define qint queue<int>
#define mip map<int,int>
#define pint priority_queue<int>
#define pb push_back
#define pp pop_back()
#define ft first
#define sd second
#define full(v) v.begin(),v.end()
int main()
{
    lld i,j,k,a,b,c,x,y,z,n,m,t;
    string s,u,v;
    cin>>c;bool ans=false;
    fr(i,0,1000){
        x=sq(i);z=x-c;
        fr(j,0,1000){
            y=sq(j);
                if(y==abs(z)){ans=true;break;}
                else if(y>abs(z)) break;
        }
        if(ans) break;
    }
    if(z>=0) cout<<i<<" "<<j<<endl;
    else cout<<i<<" "<<-j<<endl;
}