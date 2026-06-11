#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main(){

 int64_t A,b;
 cin>>A;
 double B;
 cin>>B;

 b=100*B+0.1;
 int64_t ans=A*b/100;
 cout<<ans<<endl;
}