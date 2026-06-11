#include <bits/stdc++.h>

using namespace std;
int main(){
    int a,b,output=0;
    cin>>a>>b;
    for (int i = 0;i < 1275+1; i++){
        if (floor(i * 0.08) == a && floor(i * 0.1) == b){
            output = i;
            break;
        }
    }
    output == 0 ? cout<<-1 : cout<<output; 
    return 0;
}
