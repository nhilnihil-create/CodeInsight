#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
 
int main(void)
{
    ll N,K,S;
    cin >> N >>K >>S;
    vector<int> A(N);
    for(int a=0;a<N;a++){
        if(a<K){
            A[a]=S;
        }else{
            A[a]=S+1;
        }
    }
    for(int a=0;a<N;a++){
        if(A[a]<=1000000000){
            cout << A[a]<< " ";
        }else{
            cout <<"1"<< " ";
        }
    }
    cout << endl;
}