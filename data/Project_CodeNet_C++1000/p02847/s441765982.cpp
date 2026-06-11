#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define pi       acos(-1.0)
#define test     int t;cin>>t;while(t--)
typedef long long ll;
using namespace std;
int main()
{

     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     vector<pair<string,int>>p;
     p.push_back(mp("SUN",1));
      p.push_back(mp("MON",2));
       p.push_back(mp("TUE",3));
        p.push_back(mp("WED",4));
         p.push_back(mp("THU",5));
          p.push_back(mp("FRI",6));
           p.push_back(mp("SAT",7));

    string s;
    cin>>s;
    for(int i=0;i<p.size();i++)
    {
       if(p[i].first==s)
       {
         cout<<7-(p[i].second-1)<<endl;
         return 0;
       }
    }




     return 0;

}