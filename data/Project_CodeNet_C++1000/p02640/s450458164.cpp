#include <bits/stdc++.h>
#define ll long long
#define ar array
#define nl '\n'
#define AC ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
const int M = 1e9+7;
const int N = 2*1e5;


int main(){
    AC
    int x, y;
    cin>>x>>y;
    int b = y/2-x;
    int a = 2*x-y/2;

    if(a>=0 && b>=0 && a+b==x && 2*a+4*b==y)
        cout<<"Yes"<<nl;
    else
        cout<<"No"<<nl;
}