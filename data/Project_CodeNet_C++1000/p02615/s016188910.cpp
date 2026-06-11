#include<bits/stdc++.h>
using namespace std;
int main()
{
 int n,i;
 long long int s;
 cin>>n;
 vector<long long>v(n);
 for(i=0;i<n;i++)cin>>v[i];
 sort(v.begin(),v.end());
 s=0;
 for(i=1;i<n;i++)
 {
     int l=n-1-i/2;
     s +=v[l];
 }
 cout<<s;
 return 0;
}

