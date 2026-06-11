#include <iostream>
#include <climits>

using namespace std;
#define MAX 100
#define WHITE 0
#define BLACK 1

int W[MAX][MAX],color[MAX],d[MAX],p[MAX];
int n,u,k,v,c;

int Djs()
{
   int minv,u;
   d[0]=0;
   while(1)
   {
    minv=INT_MAX;
     u=-1;
    for(int i=0;i<n;i++)
    {
       if(d[i]<minv&&color[i]!=BLACK)
       {
           minv=d[i];
           u=i;
       }
    }
    if(u==-1) break;
    color[u]=BLACK;
    for(int v=0;v<n;v++)
    {
       if(W[u][v]!=INT_MAX&&color[v]!=BLACK)
       {
           if(d[u]+W[u][v]<d[v])
           {
               d[v]=d[u]+W[u][v];
               p[v]=u;
           }
       }
    }
   }
   for(int i=0;i<n;i++)
   {
       cout<<i<<" "<<d[i]<<endl;
   }
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
     d[i]=INT_MAX;
     p[i]=-1;
     for(int j=0;j<n;j++)
     {
        W[i][j]=INT_MAX;
     }
    }
    for(int i=0;i<n;i++)
    {
     cin>>u>>k;
     for(int j=0;j<k;j++)
     {
        cin>>v>>c;
        W[u][v]=c;
     }
    }
    Djs();
    return 0;
}

