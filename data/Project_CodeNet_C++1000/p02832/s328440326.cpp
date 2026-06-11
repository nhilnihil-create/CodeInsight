#include<bits/stdc++.h>
using namespace std;
int main()
{
  int N;
  cin >> N;
  int B=0;
  int C=0;

  
  vector<int> A(N);
  for(int i=0; i<N;i++)
  {
    cin >> A.at(i);
  }
  for(int k=0; k<N;k++)
  {


      if( A.at(k)>(B+1) )
      {
        A.at(k)=-1;
      }
      

        if(A.at(k)==B+1)
        {
        B++;
        continue;
        
        }
      if( A.at(k)<(B+1) )
      {
        A.at(k)=-1;
      }   
  }
  for(int l=0;l<N;l++)
  {
    if(A.at(l)>-1)
    {
    C++;
    }
  }
  if (C==0)
  {
    cout << -1 << endl;
  }
  else
  {
  cout << (N-C) << endl;
  }
}