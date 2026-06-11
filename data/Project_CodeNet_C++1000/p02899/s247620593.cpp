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
    int order[200000];
    for (int i = 1; i <= N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
        order[A[i]] = i;
    }
    for(int i = 1; i <= N; i++){
        cout << order[i] << " ";
    }
    return 0;
}