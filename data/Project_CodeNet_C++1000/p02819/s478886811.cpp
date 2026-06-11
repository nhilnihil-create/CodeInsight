#include<bits/stdc++.h>

using namespace std;

#define lli long long int
#define pb  push_back
#define mp  make_pair

vector <lli> vv;

int main(){
    lli T, flag, res;
    cin >> T;

    if(T == 2){
        cout << "2";
        return 0;
    }
    for(lli j=T; 1; j++){
        flag = 0;
        for(lli i=3; i<=j/2; i= i+2){
            if(j%i == 0) {
                flag = 1;
                res = i;
                break;
            }
        }
        if(flag == 0){
            cout << j;
            break;
        }
    }
}
