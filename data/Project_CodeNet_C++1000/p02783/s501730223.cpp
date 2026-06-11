#include <bits/stdc++.h>
#include <vector>
#include <string.h>

typedef long long ll;
typedef long double lg;
using namespace std;


int main(){

 long long h,a;
 cin>>h>>a;

 if(h<a){
    cout<<"1"<<endl;
 return 0; }

 long long Q = h/a;

 long long number = Q*a;

 if(number >= h)
    cout<<Q<<endl;
 else if(number < h)
    cout<<Q+1<<endl;

return 0;
}