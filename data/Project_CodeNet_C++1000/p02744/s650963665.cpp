#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<map>

using namespace std;

char S[10],a[10]={'a','b','c','d','e','f','g','h','i','j'};

int N;

void rec(vector<char> A,int n)
{
  int i,j,k,m;
  
  m=A.size();
  

  
  if(m==N)
  {
    for(i=0;i<m;i++)
    {
      cout<<A[i];
    }
    cout<<endl;
    return ;
  }
  
  for(i=0;i<n+1;i++)
  {
    A.push_back(a[i]);
    if(i<n)rec(A,n);
    else rec(A,n+1);
    A.pop_back();
  }
  
}


int main()
{
  cin>>N;
  
  vector<char> A;
  A.push_back(a[0]);
  
  rec(A,1);
  
}
