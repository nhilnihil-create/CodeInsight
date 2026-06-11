#include <bits/stdc++.h>
using namespace std;


int main() {
    int n,m,q;

   cin>>n>>m>>q;
vector<int> a(q);
vector<int> b(q);
vector<int> c(q);
vector<int> d(q);
vector<int> A(10);
long int ans=0;

for (int i = 0; i < q; i++)
{
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  
}

for (int i = 1; i <=m; i++)
{
A[0]=i;
 for (int i1 = i; i1 <=m; i1++)
 {
       A[1]=i1;

    for (int i2 = i1 ;i2 <= m; i2++)
    {
       A[2]=i2;
         for (int i3 = i2; i3 <= m; i3++)
     {
         A[3]=i3;
         for (int i4 = i3; i4 <= m; i4++)
      {
           A[4]=i4;
         for (int i5 = i4; i5 <= m; i5++)
      {
           A[5]=i5;
         for (int i6 =i5; i6 <= m; i6++)
      {
        A[6]=i6;
         for (int i7 = i6; i7 <= m; i7++)
    {
          A[7]=i7;
         for (int i8 = i7; i8 <= m; i8++)
    {
           A[8]=i8;
         for (int i9 = i8; i9 <=m; i9++)
    {
       A[9]=i9;
long int sum=0;
       for (int j = 0; j < q; j++)
       {
           int fir=a[j]-1;
           int sec=b[j]-1;

           if(A[sec]-A[fir]==c[j]){
               sum+=d[j];

           }
       }
if(sum>ans){ans=sum;}
//if(A[0]==2)cout<<"yo"<<endl;

        
    
    }

    }
 
    }
   
    }

    }

    }
  
    }
    
    }
 
}
 
}
cout<<ans<<endl;
}