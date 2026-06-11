#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define F first
#define S second
#define ii pair < int , int >

const int N=1;

int main()
{
 ll a,b,k;
 cin>>a>>b>>k;
 ll tmp=min(a,k);
 k-=tmp;
 a-=tmp;
 if(k!=0){
    b=max(b-k,0LL);
 }
 cout<<a<<" "<<b;
 }
