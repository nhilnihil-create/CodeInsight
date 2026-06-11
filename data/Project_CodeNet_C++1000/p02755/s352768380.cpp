#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
 int a,b,c,d,mi; cin>>a>>b; mi=100000;
 for(int i=1;i<=10000;i++){
    c=(i*8)/100; d=(i)/10; if(c==a && mi>i && d==b){mi=i;}
 }
 if(mi<100000)cout<<mi;
 else cout<<-1;
}


