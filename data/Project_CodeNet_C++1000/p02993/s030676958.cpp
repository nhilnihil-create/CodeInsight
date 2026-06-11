#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstdio>
using namespace std;
char N[5];
int main(){
    cin >> N;
    for(int i =0;i<4;i++){
        if(N[i]==N[i+1]){
            printf("Bad\n");
            return 0;
        }
    }
    printf("Good\n");
    return 0;
}