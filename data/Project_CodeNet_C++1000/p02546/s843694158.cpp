#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<stdio.h>
#include<locale.h>
#include<set>
#include<stack>
#include<queue>
using namespace std;

int main()
{
string s;
cin >> s;
if(s[s.size()-1]=='s'){s=s+"es";}
else{s=s+"s";}
cout << s <<endl;

}
