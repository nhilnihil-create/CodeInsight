#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;


int main()
{
    int n,k;
    cin>>n>>k;vector<int>h(n);int a=0;
    for(int i=0;i<n;i++){
        int p;
        cin>>p;
        if(p>=k)a++;
    }
    cout<<a;
    return 0;
}
