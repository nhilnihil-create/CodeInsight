#include <bits/stdc++.h>
using namespace std;

int main() {

int N;
cin >> N;
//int *num=new int[3];

//int num[]={300000,200000,100000,0};
//string *name=new string[N+1];
int flag=0;
if(N%2==1)flag=1;
N/=2;

cout << N-1+flag << endl;

}
