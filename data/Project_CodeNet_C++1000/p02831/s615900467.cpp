#include<bits/stdc++.h>
using namespace std;
int main(){
    long long a,b;
    cin >> a >> b;
    if (a>b) swap(a,b);
    for (int i=1; i<=a; i++){
        if ((b*i)%a==0){
            cout << b*i;
            return 0;
        }
    }
}