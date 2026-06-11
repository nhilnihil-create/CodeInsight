#include<iostream>
#include<set>
using namespace std;
int main()
{
  long long n,i;
  cin>>n;
  long long m[n];
  for(i=0;i<n;i++)
  {
    cin>>m[i];
  }
  set<int>st;
  for(i=0;i<n;i++)
  {
    st.insert(m[i]);
  }
  if(st.size()==n)
  {
    cout<<"YES"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }
return 0;
}
