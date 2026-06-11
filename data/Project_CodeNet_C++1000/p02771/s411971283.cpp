#include <bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
    int A,B,C;
    cin >> A >> B >> C;
    bool poor=false;
    if(A==B&&A!=C){
        poor=true;
    }
    if(A==C&&A!=B) {
        poor=true;
    }
    if(B==C&&B!=A) {
        poor=true;
    }
    
    if(poor==true) {
        cout << "Yes" << endl;
    }
    else{
        cout <<"No" << endl;
    }
}
