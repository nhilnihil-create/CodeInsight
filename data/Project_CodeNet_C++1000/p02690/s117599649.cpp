#include <bits/stdc++.h>
using namespace std;

int main(){
    int x;
    cin >> x;

    for(int b=-150;b<150;b++){
        for(int a=b+1;a<151;a++){
            if(pow(a,5)-pow(b,5)==x){
                cout << a << " " << b << endl;
                return 0;
            }
        }
    }

    return 0;
}