#include <bits/stdc++.h>
using namespace std;
int main(){int a,b,c;cin>>a>>b>>c;b--;c--;vector<int>A(a-1);for(int i=0;i<a;i++)for(int j=i+1;j<a;j++)A[min(min(abs(j-i)-1,abs(j-b)+abs(i-c)),abs(j-c)+abs(i-b))]++;for(int i=0;i<a-1;i++)cout<<A[i]<<endl;}