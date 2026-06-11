#include <iostream>
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int kmod = 1e9 + 7;

vector<int>par(200006);

vector<int>cap(200006);
int find(int a)
{
    if(par[a] == a)
     return a;

  return par[a] = find(par[a]);
}
int main() {

    
    int n , m;
    cin>>n>>m;
    

    for(int i = 0 ;i<= n ;i++)
     par[i] = i,cap[i] = 1;

    for(int i = 0 ; i<m ;i++)
    {
        int a,b;
        cin>>a>>b;

       int pa = find(a);
       int pb = find(b);


       if(pa != pb)
       {
           par[pa] = pb;

           find(a);

           cap[pb] = cap[pa] + cap[pb] ;
 
           cap[pa] = 0;
       }
    }

    int omax = 0;

    for(int i = 0 ; i<= n ;i++)
    omax = max(omax , cap[i]);

    cout<<omax<<endl;
   
}
