#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argv,char* argc[])
{
    vector<pair<string,int> >ar;
    int n;
    cin>>n;
    string s; int t;
    for(int i=0;i<n;++i)
     {
         cin>>s>>t;
         ar.push_back(make_pair(s,t));
     }
     string x;
     cin>>x;
     int sum=0;
     for(int i=n-1;i>=0;--i)
     {
         if(ar[i].first!=x)
            sum+=ar[i].second;
         else break;
     }
     cout<<sum;
    return 0;
}
