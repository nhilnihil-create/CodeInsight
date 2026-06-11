#include <iostream>
using namespace std;

int main(){
    int n;
    long min,max,sum;
    cin >> n;
    long work[n];
    for(int i = 0; i < n;i++){
        cin >> work[i];
    }
    max = sum = min = work[0];
    for(int i = 1; i < n;i++){
        if(max < work[i]){
            max = work[i];
        }
        if(min > work[i]){
            min = work[i];
        }
        sum += work[i];
    }
    cout << min << " " << max << " " << sum << endl;
    return 0;
}