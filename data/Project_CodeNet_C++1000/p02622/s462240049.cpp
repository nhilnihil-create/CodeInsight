#include <iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
int cnt;
string s,t;
cin>>s>>t;
int n= s.length();
int k= t.length();

for(int i=0;i<n;i++){

     if(s[i]!=t[i])
        cnt++;

    }

cout<<cnt;
}

