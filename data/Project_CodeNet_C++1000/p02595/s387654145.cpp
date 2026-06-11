#include <bits/stdc++.h>
using namespace std;
int main(){
    long int N,D,i,x,y,a = 0;
    cin >> N >> D;
    for(i = 0;i < N;i++){
        cin >> x >> y;
        if(sqrt(x * x + y * y) <= D){
            a++;
        }
    }
    cout << a << endl;
}