#include <bits/stdc++.h>
using namespace std;

int main() {
int n1,n2;

//int *num=new int[3];

int num[]={300000,200000,100000,0};
//string *name=new string[N+1];
cin >> n1 >> n2;

if(n1>3)n1=4;
if(n2>3)n2=4;


if(n1==1 && n2==1)
cout << num[n1-1]+num[n2-1]+400000 << endl;
else
cout << num[n1-1]+num[n2-1] << endl;

}
