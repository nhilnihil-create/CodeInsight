#include <bits/stdc++.h>
using namespace std;


int main() {
int a,b,c;
cin>>a>>b>>c;
int s= max(a,b);
int op= c/s;
if(c%s >0){
    op=op+1;
}
cout<<op;



  return 0;
}