#include<bits/stdc++.h>
using namespace std;

long long int my_Min(long long int x,long long int y){
    if(x <= y){
        return x;
    }else{
        return y;
    }
}

int main(){
    long long int N,A,B;
    cin >> N >> A >>B;
    if((B - A) % 2 == 0){
        cout << (B - A)/2;
    }else{
        cout << (my_Min(A-1, N-B) + ((B-A+1)/2));
    }
}