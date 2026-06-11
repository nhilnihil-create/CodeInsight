#include<iostream>
using namespace std;

class num
{
public:
        int n;
};


int main()
{
 int a,b,m;
 cin >> a  >> b >> m;
 num A[a];
 num B[b];
 int A_min=1000000;
 int B_min=1000000;
 for(int i=0;i<a;i++){
     int v;
     cin >> v;
     A[i].n=v;
     if(v<A_min){
         A_min=v;
     }
 }
 for(int i=0;i<b;i++){
     int v;
     cin >> v;
     B[i].n=v;
     if(v<B_min){
         B_min=v;
     }
 }
 long ans=A_min+B_min;
 for(int i=0;i<m;i++){
     int x,y,c;
     cin >> x >> y >> c;
     x-=1;
     y-=1;
     long tmp=A[x].n+B[y].n-c;
     if(tmp<ans){
         ans=tmp;
     }
 }
 cout << ans;
 return 0;

}