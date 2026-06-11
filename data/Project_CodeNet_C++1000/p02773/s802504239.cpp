

#include<bits/stdc++.h>
#define l(i,a,n)for(int i=a;i<n;i++)
#define pb push_back
#define in insert
#define mp make_pair
#define lw(v) sort(v.begin(),v.end());
#define hi(v) sort(v.begin(),v.end(),greater<long long>());
#define all(v) v.begin(),v.end()
#define filein freopen ("input.txt", "r", stdin)
#define fileout freopen ("output.txt", "w", stdout)
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long t,r=1,r1=0,r2=0,k=0,a,b,c=1,m,d=0,n,e,f,x=0,g,p=0,q=0,y=0,z=0;
map<string,int>v;
vector<pair<int,string>>v1;

    vector<long long>u;
    set<long long>s;
    std::vector<int>::iterator it;
    string  s1,s2,s3,s4;
   cin>>n;
   l(i,1,n+1)
   {
       cin>>s1;
   v[s1]++;

   }
for(auto x:v){

   v1.pb({x.second,x.first});


}
lw(v1);
for(auto x:v1){
    if(x.first==v1[v1.size()-1].first)
    {
        cout<<x.second<<endl;
    }


}

}

