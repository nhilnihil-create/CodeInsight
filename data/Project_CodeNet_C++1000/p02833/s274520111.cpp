#include <bits/stdc++.h>
using namespace std ;

int main(){
    long long int N;
    cin >> N;
    if(N%2==1){
        cout << 0 << endl;
        return 0;
    }
    long long int i=1;
    long long int count=0;
    while(1){
        long long int a=2*(pow(5,i));
        if(a<=N){
            count += N/a;
        }else{
            break;
        }
        i++;
    }
    cout << count << endl;
}