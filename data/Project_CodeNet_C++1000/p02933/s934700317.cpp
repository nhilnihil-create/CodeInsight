#include <bits/stdc++.h>
using namespace std;

int main ()
{
string s;
int a;
cin>>a>>s;
if(a<=5000&&a>=2800&&s.length()>=1&&s.length()<=10){
if(a>=3200){
    cout<<s;
}
else{
    cout<<"red";
}
}
return 0;
}