#include<bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int ans = c - a + b;
    if(ans < 0){
        cout<<0;
    }
    else{
        cout<<ans;
    }
    return 0;
}
