#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>

using namespace std;

int main(void)
{
    int M, D, i, j, ans=0;

    cin >> M >> D;

    for(i=1; i<=M; i++){
        for(j=1; j<=D; j++){
            if(j/10>=2 && j%10>=2 && j/10*(j%10)==i){
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}