
#include<iostream>

using namespace std;
int main()
{

long int a,b,i,c=0,ans;
cin>>a>>b;
if(a<b)
{
for(i=a;i<=b;i++)
{
  if(abs(a-i)==abs(b-i))  
        {
        c++;
ans=i;
           break; 
        
    }
    

}
if(c==0)
cout<<"IMPOSSIBLE"<<endl;
else

cout<<i<<endl;
}

else 
{

for(i=b;i<=a;i++)
{
  if(abs(a-i)==abs(b-i))  
        {
        c++;
ans=i;
           break; 
        
    }
    

}
if(c==0)
cout<<"IMPOSSIBLE"<<endl;
else

cout<<i<<endl;

}






return 0;
}