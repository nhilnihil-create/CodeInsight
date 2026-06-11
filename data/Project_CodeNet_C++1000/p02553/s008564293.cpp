#include<bits/stdc++.h>
using namespace std;
int main(){
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  long long m_1=a*c,m_2=a*d,m_3=b*c,m_4=b*d;
  cout<<max({m_1,m_2,m_3,m_4})<<endl;
}