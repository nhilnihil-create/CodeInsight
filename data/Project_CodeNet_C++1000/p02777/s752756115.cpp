#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string a,b;
    cin >> a >> b;
    int ca,cb;
    cin >> ca >> cb;
    string s;
    cin >> s;
    if(s == a)
        ca--;
    else cb--;
    cout << ca << " " << cb;
    
    
    return 0;
}