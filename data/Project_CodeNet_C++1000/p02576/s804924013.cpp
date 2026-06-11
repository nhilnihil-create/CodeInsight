/*
    /\ In The Name of ALLAH /\
    Author : Jawahiir Nabhan
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,x,t; cin>>n>>x>>t;
    int cnt = n/x;
    if(n % x) cnt++;
    cout<<cnt*t<<endl;
}
