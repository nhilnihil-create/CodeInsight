#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int N;
    cin >> N;
    int x;
    int y;

    x = int(N/1.08);
    

    if(int(x * 1.08) == N){
        cout << x;
    }else if(floor(x * 1.08) < N){
        y = x;
        for(; floor(y * 1.08) < N+1; y++){
            if(int(y * 1.08) == N){
                cout << y;
                goto OUT;
            }
        }
        cout << ":(";
    }
    else{
        cout << ":(";
    }

OUT:
return 0;

}
