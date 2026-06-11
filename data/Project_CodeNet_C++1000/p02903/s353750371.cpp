#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
 int h,w,a,b;
 int i,j,k;
 cin>>h>>w>>a>>b;
 vector<vector<int> > aux(h,vector<int>(w,0));
 vector<int> fila(h+1,0);
 vector<int> columna(w+1,0);
 if(w-a<a || h-b<b)
 {
  cout<<"-1";
  return 0;
 }
a=w-a;
b=h-b;
for(i=0;i<h;i++)
{
 for(j=0;j<w;j++)
 {
  if(fila[i]<a && columna[j]<b)
  {
   fila[i]+=1;
   columna[j]+=1;
   aux[i][j]=1; 
  }
 }
}
for(i=0;i<h;i++)
{
 for(j=0;j<w;j++)
 {
  cout<<aux[i][j]; 
 }
 if(i!=h-1) cout<<endl;
}
 
 return 0;  
}