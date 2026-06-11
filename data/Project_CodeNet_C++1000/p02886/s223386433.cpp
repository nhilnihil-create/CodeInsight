#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;
int main(){
    int N;
    cin >> N;
    int d[N];
    int p[N];
    for(int i=0;i<N;i++)cin >> d[i];
    
    int sum = 0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            sum += d[i] * d[j];
        }
    }
    cout << sum << endl;
}
