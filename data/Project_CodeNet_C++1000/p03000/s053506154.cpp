#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    int l[100];
    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> l[i];
    }
    int now = 0;
    int bound = 1;
    for(int i=0;i<n;i++){
        now += l[i];
        if(now > x){
            break;
        }else{
            bound++;
        }
    }
    cout << bound;
    return 0;
}