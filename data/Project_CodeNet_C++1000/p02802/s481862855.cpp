#include<bits/stdc++.h>
using namespace std;
bitset<200000>md;
int arr[200000];
int main()
{

    int n,m,c=0,p=0;
    string s;
    int a;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
cin>>a>>s;
if(md[a]==0){
    if(s=="WA")arr[a]++;
    else {c++; md[a]=1;p+=arr[a];}
}
    }
    cout<<c<<" "<<p<<endl;
}
