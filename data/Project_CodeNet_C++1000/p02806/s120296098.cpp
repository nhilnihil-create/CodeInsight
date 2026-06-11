#include <bits/stdc++.h>

using namespace std;

 
 
int main() {
   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
     

      
    vector<pair<string,int>> v;
    int n,k,sum=0;
    cin>>n;
    string s,x;
    int i;
    
    for(i=0;i<n;++i)
       {
           cin>>s>>k;
           sum+=k;
           v.push_back(make_pair(s,k));
       }
       
     cin>>x;
     
     for(i=0;i<v.size();++i)
      {
          if(v[i].first==x)
             {
                 sum-=v[i].second;
                 break;
             }
             
            sum-=v[i].second; 
      }
      
      cout<<sum;
      
         
	return 0;
	
} 