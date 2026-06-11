#include<bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <iostream>

 using namespace std;

int main(){

 long long a,b,c;
 cin>>a>>b>>c;

 long long ans = c-a-b;

 if(ans < 0){
    cout<<"No"<<endl;
   return 0;
 }

 ans *= ans;
 long long y = 4*a*b;


 if(y< ans)
    cout<<"Yes"<<endl;
 else
    cout<<"No"<<endl;

return 0;
}
