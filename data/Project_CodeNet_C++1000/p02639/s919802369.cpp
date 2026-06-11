#include<bits/stdc++.h>
using namespace std;

int main(){
    int num;
    int flag;
    for(int i=0; i<5; i++){
        cin >> num;
        if(num==0) flag=i+1;
    }
    cout << flag << endl;
}