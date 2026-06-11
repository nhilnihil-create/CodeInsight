#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    float X1=(float)N/1.08;
    float X2=X1+1;
    bool judge1=true;
    bool judge2=true;
    if((int)((int)X1*1.08)!=N){
        judge1=false;
        if((int)((int)X2*1.08)!=N){
            judge2=false;
        }
    }
    if(judge1){
        cout << (int)X1 << endl;
    }
    else if(judge2){
        cout << (int)X2 << endl;
    }
    else{
        cout << ":(" << endl;
    }
}
