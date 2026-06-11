#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
        int n,d;
        cin >> n >> d;

        int i = 0;
        while(1){
            if((2*d+1)*i>=n){cout << i << endl; return 0;}
            i++;
        }
}