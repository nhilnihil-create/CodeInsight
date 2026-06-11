#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    int A[200000];
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    int maxnum = 0;
    int secondnum = 0;
    int maxkey;
    int secondkey;
    for(int i = 0; i < N; i++){
        if(maxnum < A[i]){
            maxnum = A[i];
            maxkey = i;
        }
        else if(secondnum < A[i] && A[i] <= maxnum){
            secondnum = A[i];
            secondkey = i;
        }
    }
    for(int i = 0; i < N; i++){
        if(i == maxkey){
            cout << secondnum << endl;
        }
        else{
            cout << maxnum << endl;
        }
    }
    return 0;
}