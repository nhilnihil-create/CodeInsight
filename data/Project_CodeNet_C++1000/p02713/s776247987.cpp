#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    
    int r = 0;
    int result = 0;
    while(1){
        r = a % b;
        a = b;
        b = r;
        if(r == 0){
            result = a;
            break;
        }
    }

    return result;
}

int main(void)
{
    int K;
    cin >> K;

    int sum = 0;
    for(int i = 1;i <= K;i++){
        for(int j = 1; j <= K;j++){
            for(int l = 1; l <= K;l++){  
                //cout << gcd(gcd(i,j),l) << endl;       
                sum += gcd(gcd(i,j),l);
            }        
        }
    }
    cout << sum << endl;
    return 0;
}