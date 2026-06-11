#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    string s;
    cin>>s;
    int c=0;
    for(int i=65;i<=90;i++){
        for(int j=0;j<4;j++){
            if(s[j]==i){
                c++;
                break;
            }
        }
        if(c>2)
            break;
    }
    if(c==2)
        cout<<"Yes";
    else
        cout<<"No";
}
