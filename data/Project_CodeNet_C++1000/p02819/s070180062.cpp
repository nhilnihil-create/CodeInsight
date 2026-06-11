#include <bits/stdc++.h>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <math.h>
using namespace std;

int main(void){
    int x;
    cin >> x;
    while(true){
        int w=0;
        int low = sqrt(x);
        for(int i=2;i<=low;i++){
            if(x%i==0){
                w++;
                break;
            }
        }
        if(w==0){
            break;
        }
        x++;
    }

    cout << x << endl;
	return 0;
}
