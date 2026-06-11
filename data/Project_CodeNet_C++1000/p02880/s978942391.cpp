#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int n, i, j, c = 0;
    cin >> n;
    for(i = 1; i <= 9; i++){
        if(n % i == 0){
            if(n / i <= 9){
                cout << "Yes";
                break;
            }
        }
        c++;
    }

    if(c == 9 && i != 9){
        cout << "No";
    }


}





///promy_pompom
//hello world