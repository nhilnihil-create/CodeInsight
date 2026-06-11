#include<bits/stdc++.h>
using namespace std;
 
int main(){
 
    int N;
    cin >> N;
 
    int l = (int)(N/1.08) - 5;
    int r = l + 10;
    bool check = false;
 
    for(int i=l; i<r; i++){
        if((int)(i*1.08) == N){
            cout << i << endl;
            check = true;
            break;
        }
    }
    if(check != true)
        printf(":(\n");
}