#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
int k,a,b;
cin>>k;
cin>>a;
cin>>b;
 int x=b/k;
 int y=x*k;
 if(y>=a && y<=b)
    cout<<"OK";
 else
    cout<<"NG";

    return 0;
}
