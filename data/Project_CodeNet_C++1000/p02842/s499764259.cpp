#include <bits/stdc++.h>
#include <stdio.h>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    int answer = 50001;
    for(int i = 1; i <= 50000; i++){
        if(n == floor(i*1.08)){
            answer = i;
            break;
        } 
    }
    if(answer == 50001){
        cout << ":(";
    } else {
        cout << answer;
    }
}