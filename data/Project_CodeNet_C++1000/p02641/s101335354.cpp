
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int arra[m+5];
    map<int,int>mp;
    for(int i=0;i<m;i++) {
        cin>>arra[i];
        mp[arra[i]]++;
    }
    int fnd=0;
    int val=n;
    while(fnd!=1) {
        if(!mp[val]) {
            fnd=1;
        }
        else {
            val++;
        }
    }
    fnd=0;
    int a1=abs(n-val);
    int one=val;
    val=n;
    while(fnd!=1) {
        if(!mp[val]) {
            fnd=1;
        }
        else {
            val--;
        }
    }
    int a2=(n-val);
    int two=val;
    if(a1>=a2) {
        cout<<two<<endl;
    }
    else cout<<one<<endl;









}
