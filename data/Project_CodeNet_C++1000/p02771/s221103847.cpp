#include<bits/stdc++.h>

using namespace std;

int main(){
    long a,b,c;
    cin >> a >> b >> c;
    if((a==b && a!=c) || (a==b && b!=c) || (a!=b && c==a) || (b==c && a!=b))
       cout << "Yes" << endl;
    else
       cout << "No" << endl;
    return 0;
}