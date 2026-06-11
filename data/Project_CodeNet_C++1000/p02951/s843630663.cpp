
#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(){

 int a,b,c;
 cin>>a>>b>>c;

 int left = a-b;

 if(left > c)
    cout<<"0"<<endl;
else
 cout<<c-left;

return 0;
}