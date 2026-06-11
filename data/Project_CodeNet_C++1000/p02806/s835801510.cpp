#include<iostream>
using namespace std;
struct song{
  string s;
  int x;
};
int main()
{
  int n;
  cin>>n;
  struct song songs[n];
  for(int i=0;i<n;i++)
  {
    cin>>songs[i].s;
    cin>>songs[i].x;
  }
  int sum=0;
  string s1;
  cin>>s1;
  int q;
  for(int i=0;i<n;i++)
  {
    if(songs[i].s==s1)
    {
      q=i;
      break;
    }
  }
  for(int i=q+1;i<n;i++)
  {
    sum=sum+songs[i].x;
  }
  cout<<sum;
}
  