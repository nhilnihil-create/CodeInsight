#include <bits/stdc++.h>
using namespace std;

int main(){
    long a,v,b,w,t;
    cin >> a >> v >> b >> w >> t;
    long dx;

    if(a-b<0){
        dx = b-a;
        if(v-w<=0) cout << "NO";
        else{
            if(dx<=(v-w)*t) cout << "YES";
            else cout << "NO";
        }
    }
    if(a-b>0){
        dx = a-b;
        if(v-w<=0) cout << "NO";
        else{
            if(dx<=(v-w)*t) cout << "YES";
            else cout << "NO";
        }
    }
    else if(a==b) cout << "YES";
}