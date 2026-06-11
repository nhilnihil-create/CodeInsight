#include<iostream>
using namespace std;
int main (void){

    int n, i, j, z, min, w[100];
    int a = 0, b = 0, c = 0; 

    cin >> n;

    for(i = 0;i < n;i++){

        cin >> w[i];

    }

    for(i = 0;i < n;i++){
        
        for(j = i;j >= 0;j--){

            a += w[j];
        }
        for(z = i + 1;z < n;z++){

            b += w[z];
        }

        c = a - b;
        if(c < 0)
            c *= -1;

        if(i == 0)
            min = c;

        if(min > c)
        min = c;

        a = 0, b = 0;
    }    

    cout << min << endl;
    return 0;
}