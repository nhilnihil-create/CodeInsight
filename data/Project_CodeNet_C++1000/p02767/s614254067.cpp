#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int min(int a,int b){
    return a<b?a:b;
}
int main(void){
    int N;
    vector<int> X;
    cin >> N;
    for(int i=0;i<N;i++){
        int x;
        cin >> x;
        X.push_back(x);
    }
    int ans = 100000000;
    for(int i=1;i<=100;i++){
        int sum = 0;
        for(int j=0;j<N;j++){
            sum += (X[j] - i)*(X[j] - i);
        }
        ans = min(ans,sum);
    }
    cout << ans ;
}
