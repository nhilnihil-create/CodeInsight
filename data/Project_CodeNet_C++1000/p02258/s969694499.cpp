#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>

using namespace std;



int main(){
    int A[200001];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d",&A[i]);
    }
    int mini = A[0];
    int maxcost = A[1]-A[0];
    
    for (int i = 1; i < n-1; i++) {
        mini = min(mini,A[i]);
        maxcost = max(maxcost,A[i+1]-mini);
    }
    
    cout << maxcost << endl;
    return 0;
}