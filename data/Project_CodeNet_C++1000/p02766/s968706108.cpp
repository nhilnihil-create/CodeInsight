#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, a=0;
    cin>>n>>m;
    while(n>0){
        n=n/m;
        a++;
    }
    cout<<a;
}
