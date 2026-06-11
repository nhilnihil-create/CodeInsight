#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
 
#define rep(i,N) for(int i=0;i<(int)N;i++)
bool joken(int a,int b,int c);
 
int main()
{
  int N;
  cin>>N;
  vector<int> L(N,0);
  int number=0;	//条件に合致する組み合わせの数
  
  rep(ni,N)
  {
    cin>>L[ni];
  }
  
  if(N<3)
  {
    cout<<0<<endl;
    return 0;
  }
  
  rep(ni,N-2)
  {
    for(int nj=ni+1;nj<N-1;nj++)
    {
      for(int nk=nj+1;nk<N;nk++)
      {
        if(joken(L[ni],L[nj],L[nk]))
             number++;
      }
    }
  }
  cout<<number<<endl;
  return 0;
}
 
bool joken(int a,int b,int c)
{
  if((a==b)||(b==c)||(c==a))
    return false;
  
  if(((a+b)>c)&&((b+c)>a)&&((c+a)>b))
    return true;
  else
    return false;
}