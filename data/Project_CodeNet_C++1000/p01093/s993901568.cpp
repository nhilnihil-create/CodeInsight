#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    int a[1001];
    int n;
    while(cin >> n){
        if(n == 0)  break;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int min = 10000001;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(fabs(a[i]-a[j]) < min){
                    min = fabs(a[i]-a[j]);
                }
            }
        }
        cout << min << endl;
    }
    
    return 0;
}

