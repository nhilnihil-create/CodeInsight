#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,b,n,m,x,y,z,i=0,ans=0,c=0,r;
    string s,t,u;
    cin >> s >> t >> a >> b >> u;
    if(s==u)
    {
        cout << a-1 << " " << b << endl;
        return 0;
    }
    else
    {
        cout << a << " " << b-1 << endl;
    }
    return 0;
}
