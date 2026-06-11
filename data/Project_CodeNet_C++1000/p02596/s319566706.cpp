#include<bits/stdc++.h>
using namespace std;

int main(){
    int k; cin >> k;
    
    //kが2の倍数かそうでないか
    if(k%2 == 0){
        cout << "-1" << endl;
    }else{
        long long int a = 7;
        for(int i=0; i<k; i++){
            if(a % k == 0){
                cout << i+1 << endl;
                exit(0);
            }else{
                a %= k;
                a = 10*a + 7;
            }
        }

        cout << "-1" << endl;
    }
}