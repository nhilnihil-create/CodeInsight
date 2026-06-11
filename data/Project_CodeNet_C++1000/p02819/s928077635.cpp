#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int x;
    cin >> x;
    while(true){
        bool is_prime = false;
        for(int i = 2; i * i <= x; i++){
            if(x % i == 0)
                is_prime = true;
        }
        if(!is_prime){
            cout << x << endl;
            return 0;
        }
        x++;
    }
    return 0;
}