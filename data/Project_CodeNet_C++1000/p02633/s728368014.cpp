#include <bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin>>x;
    int a=360;
    while(a%x!=0){
        a+=360;
    }
    cout<<a/x;
    return 0;
}
