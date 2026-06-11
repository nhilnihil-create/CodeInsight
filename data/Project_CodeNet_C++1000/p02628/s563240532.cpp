#include <iostream>
using namespace std;

int main() {
int N,i,j,k,t,s=0;
cin>>N>>k;
int p[N];
for(i=0;i<N;i++)
{
    cin >>p[i];
}
  
for(i=0;i<N;i++)  

 {   for(j=i;j<N;j++)
    {
        if(p[i]>p[j])
        {
            t=p[i];
            p[i]=p[j];
            p[j]=t;
        }
    }}


for(i=0;i<k;i++)
{
    s+=p[i];
}
cout<<s<<endl;
    return 0;
}