#include <iostream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <ctype.h>

using namespace std;

int main() {
    int n;
    while((cin>>n)){
        if(n==0){
            break;
        }
        int a[n];
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        int max = -99999999;
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum += a[j];
                if(max<sum){
                    max=sum;
                }
            }

        }
        cout<<max<<endl;
    }
    return 0;
}