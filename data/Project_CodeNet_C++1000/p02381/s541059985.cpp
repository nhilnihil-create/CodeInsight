#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main() {
    int n;

    while (1){
        cin >> n;
        if(n==0){
            break;
        }
        
        int s[1000];
        double m=0,sig=0;

        for(int i=0;i<n;i++){
            cin >> s[i];
            m+=s[i];
        }
        m=m/n;

        for(int j=0;j<n;j++){
            sig+=pow(s[j]-m,2);
        }

        printf("%.6lf\n",sqrt(sig/n));
    }

    return 0;
}