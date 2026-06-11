#include <bits/stdc++.h>

using namespace std;



int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);
   
   long long int n,i,m1,cnt1=0,cnt2=0;
   cin>>n>>m1;
   long long int p[m1];
   long long int h[n+1]={0};
   string s[m1];
   set<long int > st;

    
    for(i=0;i<m1;++i)
     {
         cin>>p[i]>>s[i];
     }
     
    for(i=0;i<m1;++i)
     {
         if(s[i]=="AC")
           {
              if(st.count(p[i])==0)
                {
                    st.insert(p[i]);
                    
                }
           }
           
          else
           {
               if(st.count(p[i])==1)
                 continue;
                 
               else
                 h[p[i]]++;
           }
     }
     
     for(i=1;i<=n;++i)
      {
          if(st.count(i)==1)
            cnt1+=h[i];
      }
      
      cout<<st.size()<<" "<<cnt1;
    
        
   
     return 0;
}