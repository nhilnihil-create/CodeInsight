#include<bits/stdc++.h>
using namespace std;


int main(){
    int a, b;
    int tap=1;
    int res=0;
    cin >> a >> b;
    while(tap<b){
        tap += (a-1);
        res++;
    }

    cout << res << endl;

}