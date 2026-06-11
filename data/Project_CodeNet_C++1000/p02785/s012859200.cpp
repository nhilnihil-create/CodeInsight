#include<bits/stdc++.h>
using namespace std;
#define ll long long  
int main()
{ int n,k;
 cin>>n>>k;
 vector<int> a(n);
 for(auto &x:a)
 cin>>x;
 sort(a.begin(),a.end());
 ll answer =0;
 for(int i=0;i<n-k;i++) 
  answer+=a[i];
  cout<<answer;
 
}