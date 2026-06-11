#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a;
    cin>>a;
    a= a - (a/10)*10;
    if(a==2 || a == 4 || a==5 || a== 7 || a== 9)
        cout<<"hon";
    else if(a== 3)
        cout<<"bon";
    else
        cout<<"pon";
    return 0;
}
