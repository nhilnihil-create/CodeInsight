#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void boost(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int main(){
    boost();
    double d,t,s;
    cin >> d >> t >> s;
    double d1=d/s;
    if(d1<=t)
    cout << "Yes" << endl;
    else
    cout << "No" << endl;
}