#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
int N;
cin>>N;
int counter=0;
for(int i=1;i<=N;++i)
{
    int n;
    cin>>n;
    if(i%2!=0&&n%2!=0)
        counter++;
}
cout<<counter;
    return 0;
}
