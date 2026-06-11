#include <iostream>
using namespace std;

int main()
{
    int n; 
    cin >> n;
    int c[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++) c[i][j] = 0;
    }


    for(int i=1; i<=n; i++){
        int a = i;
        while(1){
            if(a/10 == 0) break;
            a /= 10;
        }
        c[a][i%10]++;
    }

    int ans = 0;

    for(int i=1; i<10; i++){
        for(int j=1; j<10; j++){
            ans += c[i][j]*c[j][i];
        }
    }

    cout << ans << endl;
}