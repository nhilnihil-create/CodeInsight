 #include<iostream>
 #include<stdio.h>
 #include<string>
 #include<math.h>
 #include<iomanip>
 #include<algorithm>
 #include<string.h>
 #include<cctype>
 #include<map>
 #include<set>
 #include<vector>
 #include<sstream>
 #include<stack>
 #include<queue>
 
 using namespace std;
 
 const int MAX_N=10000+5;
 int n;
 int par[MAX_N];
 int rank[MAX_N];
 
   void init()
   {
     for(int i=0;i<n;i++)
     {
       par[i]=i;
       rank[i]=0;        
     }     
   }
   
   int find(int x)
   {
     if(par[x]==x) return x; 
     else return par[x]=find(par[x]);    
   }
   
   void unite(int x,int y)
   {
     x=find(x);
     y=find(y);
     if(x==y) return;
     if(rank[x]<rank[y]) par[x]=y;
     else
     { 
       par[y]=x;
       if(rank[x]==rank[y]) rank[x]++;
     }     
   }
   
   bool same(int x,int y)
   {
     //cout<<find(x)<<" "<<find(y)<<endl;
     return find(x)==find(y);     
   }

  int main()
 {
   int q;
   cin>>n>>q;
   init();
   while(q--)
   {
     int a,b,c;
     cin>>a>>b>>c;
     if(a==0) unite(b,c);
     else
     {
       if(same(b,c)) cout<<"1"<<endl;
       else cout<<"0"<<endl;    
     }            
   }
    //while(1);
    return 0;
 }

 
 