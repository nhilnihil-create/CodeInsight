#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >>b;
    int count=1;
    int socket =0;
    while(count<b){
        count--;
        count+=a;
        socket++;
        
    }
    cout << socket <<endl;
}