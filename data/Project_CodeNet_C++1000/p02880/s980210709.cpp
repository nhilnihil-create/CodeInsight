#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, chk = 0;
    cin >> n;
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(i*j == n){
                chk = 1;
            }
        }
    }
    if(chk == 1)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
