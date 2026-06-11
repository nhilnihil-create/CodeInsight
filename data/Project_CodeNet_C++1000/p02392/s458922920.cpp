#include <iostream>
using namespace std;main(){int a,b,c;cin>>a>>b>>c;char d[2][4]={"No","Yes"};cout<<d[a<b?b<c:0]<<endl;}