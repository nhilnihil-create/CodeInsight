#include <bits/stdc++.h>
using namespace std;
void Fizz(int i,int n,unsigned long int sum){
    
    if(i == n){
        if(i%3 != 0 && i%5 != 0) sum+=i;
        cout << sum << endl;
    }
    else{
        if(i%3 != 0 && i%5 != 0){
            Fizz(i+1,n,sum+i);    
        }
        else{
            Fizz(i+1,n,sum);
        }
    }
}

int main() {
    
    int n;
    cin >> n;
    Fizz(1,n,0);
}