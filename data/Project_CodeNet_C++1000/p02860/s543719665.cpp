#include<bits/stdc++.h>
#define pb       push_back
#define mp       make_pair
#define mod      1000000007
#define first    ff
#define second   ss
#define pi       acos(-1.0)
typedef long long ll;
using namespace std;
vector<int>node[10001];

int main()
{      


     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n%2)
      cout<<"No"<<endl;
    else
    {
       string a="",b="";
       
       for(int i=0;i<n;i++)
       {
          if(i<n/2)
            a+=s[i];
          else
            b+=s[i];
        
       }        
             if(a==b)
            cout<<"Yes"<<endl;
          else
            cout<<"No"<<endl; 
    }


      return 0;
    
 }       
