#include<bits/stdc++.h>
#define ll 	long long
#define pb push_back
#define mp make_pair
using namespace std;

int main(){

ll n,m,d=0,e=0;
cin>>n>>m;

 d=n*m;

if(d==n || d==m)
e=1;
else if(d%2)
 e=(d+1)/2;
else
 e=d/2;

cout<<e<<endl;
    return 0;
}