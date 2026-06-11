#include<iostream>
using namespace std;

int main()
{
  long long int a,b,c,d;
  cin>>a>>b>>c>>d;
  long long int ans1=a*d;
  long long int ans2=a*c;
  long long int ans3=b*c;
  long long int ans4=b*d;
  cout<<max(ans1,max(ans2,max(ans3,ans4)))<<endl;
}