#include <iostream>
#include <cmath>
using namespace std;

int main(void){
    while(true){
        int n;
        cin >> n;
        if(n==0)break;
        
        double s[n];
        for(int i = 0;i<n;i++){
            int v;
            cin >> v;
            s[i] = v;
        }
        double sum = 0;
        for(int i = 0;i<n;i++){
            sum += s[i];
        }

        double ave = sum / n;

        double sum2 = 0;
        for(int i = 0;i<n;i++){
            sum2 += pow((s[i] - ave),2);
        }
        
        double ave2 = sum2 / n;
        
        double ans = sqrt(ave2);
        
        cout << fixed << ans << endl;
    }

}