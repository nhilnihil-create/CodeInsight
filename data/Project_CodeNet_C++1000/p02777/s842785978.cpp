#include <iostream>
#include<set>
#include<map>
#define INF 1e8
using namespace std;
int main(void){
string s,t;
int a,b;

cin>>s>>t>>a>>b;
string d;
cin>>d;
if(d==s)
    a--;
else
    b--;
cout<<a<<" "<<b;

}

