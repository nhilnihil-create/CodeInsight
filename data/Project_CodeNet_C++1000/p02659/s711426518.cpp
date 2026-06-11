#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
 
    ull a,b;
	string s;
 
    cin>>a>>s;
    b=(s[0]-'0')*100+(s[2]-'0')*10+s[3]-'0';
    cout<<a*b/100<<endl;
 
   
}