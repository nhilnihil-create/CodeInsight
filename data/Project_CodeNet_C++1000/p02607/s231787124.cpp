#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,x,square=0;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin >>x;
        if ( (i+1)%2 == 1 && x%2 == 1 )
            square++;
    }
    cout << square <<endl;


}