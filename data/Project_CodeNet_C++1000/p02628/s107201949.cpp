#include <iostream>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int p[n];
    for (int i = 0; i < n; i++)
        cin>>p[i];
    int min_index = 0;
    int sum = 0;
    for (int i = 0; i < k; i++){
        int min = 100000;
        for (int j = 0; j < n; j++){
            if (min > p[j]){
                min = p[j];
                min_index = j;
            }
        }
        sum += min;
        p[min_index] = 10001;
    }
    cout<<sum;
    return 0;
}