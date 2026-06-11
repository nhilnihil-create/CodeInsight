#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;
    int x=0;
 
    for(int a=1; a<=N-1; a++){
        x+=(N-1)/a;
    }

    cout << x << endl;
}