#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int a,b,n,x,y,z,i=0,ans=0,c=0,r;
    string s;
    cin >> a >> b >> c;
    if((a==b && b==c) || (a!=c && c!=b && b!=a) )
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }    
        
    return 0;
}
