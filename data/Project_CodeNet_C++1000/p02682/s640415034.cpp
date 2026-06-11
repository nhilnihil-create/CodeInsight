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
    int a, b, c, k;
    cin>>a>>b>>c>>k;
    if(k<=a+b)
        cout<<(k<=a ? k : a)<<endl;
    else
        cout<<a-(k-(a+b))<<endl;

}