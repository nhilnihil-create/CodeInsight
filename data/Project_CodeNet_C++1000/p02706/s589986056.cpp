#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;
    cin>>n>>a;
    int s = 0;
    while(a--){
        int k;
        cin>>k;
        s+=k;
    }
    if(s>n) puts("-1");
    else cout<<n-s;
}
