#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b ,inp;
    int c,d;
    cin >> a>>b>>c>>d>>inp;
    if(inp == a){
        cout<< c-1 << " " << d;
    }
    else{
        cout<< c << " " << d-1;
    }
}