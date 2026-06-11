#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    int cnt = 0;
    cin >> a >> b >> c;
    if(a==b){
        cnt++;
    }
    if(a==c){
        cnt++;
    }
    if(b==c){
        cnt++;
    }
    if(cnt==1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}