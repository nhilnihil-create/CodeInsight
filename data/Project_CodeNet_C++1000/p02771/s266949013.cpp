#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int A,B,C;
    cin >> A >> B >> C;
    int count = 0;
    if(A == B)count++;
    if(A == C)count++;
    if(B == C)count++;
    
    if(count == 1){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
}
