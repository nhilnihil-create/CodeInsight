#include<bits/stdc++.h>
using namespace std;
int main(){
    int64_t x;
    cin >> x;
    for(int64_t a=-200; a<200; a++){
        for(int64_t b=-200; b<200; b++){
            if(a*a*a*a*a - b*b*b*b*b == x){
                cout << a << ' ' <<  b << endl;
                return 0;
            }
        }
    }
}
