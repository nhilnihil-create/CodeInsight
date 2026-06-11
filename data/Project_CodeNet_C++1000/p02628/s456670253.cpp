#include<bits/stdc++.h>
using namespace std;
int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);

int n,k,c=0;       cin>>n>>k;
int x[n];
for(int i=0;i<n;i++)
{
    cin>>x[i];
}
sort(x,x+n);
for(int i=0;i<k;i++)
{
  c+=x[i];
}

cout<<c<<endl;






return 0;}
