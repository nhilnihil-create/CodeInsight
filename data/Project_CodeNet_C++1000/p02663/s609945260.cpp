#include<bits/stdc++.h>
using namespace std;

int main()
{ 
    int h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    int tot = (h2-h1)*60 + (m2-m1);
    tot -= k;
    cout<<tot<<endl;
}
