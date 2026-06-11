#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
 string str,ptr; cin>>str>>ptr; int n=str.length(),c=0;
 for(int i=0;i<n;i++){
    if(str[i]==ptr[i])c++;
 } if(c==n)cout<<"Yes"; else cout<<"No";
}


