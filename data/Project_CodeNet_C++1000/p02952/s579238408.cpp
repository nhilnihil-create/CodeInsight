#include<bits/stdc++.h>
using namespace std;

int GetDigit(int num){
    int digit = 0;
    while(num!=0){
        num /= 10;
        digit++;
    }
    return digit;
}

int main(){
    int N;
    cin >> N;
    int count=0;
    for(int i=1; i<=N; i++){
        if(GetDigit(i)%2 ==1){
            count++;
        }
    }
    cout << count << endl;
}