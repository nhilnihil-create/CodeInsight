#include <bits/stdc++.h>
using namespace std;

int main()
{
  int A,B,C,a,b,c,K;
  cin >> A >> B>>C>>K;
  for(int i=0;i<=K;i++)
    for(int j=0;j<=K-i;j++)
      for(int s=0;s<=K-i-j;s++){
        a = (i==0)? A : A*pow(2.0,(double)i);
        b = (j==0)? B : B*pow(2.0,(double)j);
        c = (s==0)? C : C*pow(2.0,(double)s);
        if(a<b&&b<c){ cout << "Yes" << endl; return 0; }
      }
  cout << "No" << endl;
}