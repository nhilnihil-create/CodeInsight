#include<bits/stdc++.h>
using namespace std;

int main(){

    int k,x,i;
    cin >> k >> x;

    if(k==0)
        cout << "0" << endl;
    else{
        for(i=x-k+1;i<=x+k-1;i++)
            cout << i << " ";
        cout << endl;
    }
    
    return 0;
}