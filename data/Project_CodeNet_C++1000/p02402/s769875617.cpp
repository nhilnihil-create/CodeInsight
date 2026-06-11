#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

int main(){

        int n,min,max,tmp;
        int i = 1;
        long sum;
        cin >> n;

        for(int i = 1; i <= n; i++){
                cin >> tmp;
                sum += (long)tmp;
                if(i == 1){
                        min = tmp;
                        max = tmp;
                }

                if(tmp < min) min = tmp;
                else if(tmp > max) max = tmp;
        }
        
        cout << min << " " << max << " " << sum << "\n";
        return 0;
}