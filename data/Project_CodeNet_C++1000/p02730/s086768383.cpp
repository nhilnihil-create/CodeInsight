/*
START BY THE NAME OF ALMIGHTY ALLAH
THIS WONT BE ACCEPTED
STOP_GIVING_UP

██╗███████╗████████╗██╗ █████╗ ██╗  ██╗
██║██╔════╝╚══██╔══╝██║██╔══██╗██║ ██╔╝
██║███████╗   ██║   ██║███████║█████╔╝
██║╚════██║   ██║   ██║██╔══██║██╔═██╗
██║███████║   ██║   ██║██║  ██║██║  ██╗
╚═╝╚══════╝   ╚═╝   ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝




*/
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
    long long t,r=1,r1=0,r2=0,k=0,a,b,c=1,m,d=100,n,e,f=0,x=0,g,p=0,q=0,y=0,z=0;

    vector<pair<long long,long long>>v;
    vector<long long>u;
    map<string,long long>s;
    std::vector<int>::iterator it;
    string  s1,s2,s3,s4,s5,s6;
  cin>>s1;
  a=s1.size();
  s2=s1;
  reverse(all(s1));
  s3=s1.substr(0,a/2);
  s4=s3;
  reverse(all(s4));
   s5=s1.substr((a+3)/2-1,(a-(a+3)/2)+1);
  s6=s5;
  reverse(all(s6));
//cout<<s1<<" "<<s2<<endl;
//cout<<s3<<" "<<s4<<endl;
//cout<<s5<<" "<<s6<<endl;

  if(s1==s2&&s3==s4&&s6==s5)
  {
      cout<<"Yes";
  }
  else{cout<<"No";}


}
