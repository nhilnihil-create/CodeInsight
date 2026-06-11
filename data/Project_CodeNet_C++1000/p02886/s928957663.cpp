#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std ;
int N;
int main(){
    cin >> N;
    int d[N];
    for(int i=0;i<N;i++)cin >> d[i];
    int sum = 0;
    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            sum += d[i] * d[j];
        }
    }
    cout << sum << "\n";
}