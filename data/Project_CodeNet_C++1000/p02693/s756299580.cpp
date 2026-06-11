#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main()
{
    int a, b, k, i;
    cin >> k >> a >> b;
    for(i = a; i <=b; i++){
        if(i % k == 0){
            cout << "OK";
            break;
        }
    }
    if(i == b+1){
        cout << "NG";
    }



}





///promy_pompom
//hello world
