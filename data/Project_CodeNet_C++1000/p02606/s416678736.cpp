#include <bits/stdc++.h>
using namespace std;
int main() {
    int L,R,d;
    cin>>L>>R>>d;
    if(L%d==0){
        cout<<(R/d)-(L/d)+1;
    }
    else
    cout<<(R/d)-(L/d);
}