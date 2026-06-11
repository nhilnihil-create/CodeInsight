#include <iostream>
#include <algorithm>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int N;
    cin >> N;
    int A[N];
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A,A+N);
    string ans = "YES";
    for(int i=0;i<N-1;i++){
        if(A[i] == A[i+1])ans="NO";
    }
    cout << ans << endl;
}
