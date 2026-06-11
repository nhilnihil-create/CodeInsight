#include"bits/stdc++.h"
using namespace std;
int ce(int a,int b){ if(a%b==0) return a/b; return a/b+1; }
int main()
{
  ios_base::sync_with_stdio(false); cin.tie(0); 
  int n,d; cin>>n>>d; cout<<ce(n,2*d+1)<<"\n";  
  return 0;
}