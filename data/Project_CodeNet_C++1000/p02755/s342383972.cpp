#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    int a, b;
    cin>>a>>b;
    int start = ceil((double)(a/0.08));
    int end = ((a+1)/0.08);
    if((double)(end*0.08) != (double)a){
        end -= 1;
    }
    for(int i = start; i <= end; i++){
        if((int)(i*0.1) == b){
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}