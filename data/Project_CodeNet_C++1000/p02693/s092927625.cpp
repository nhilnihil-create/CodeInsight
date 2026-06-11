#include <iostream>
#include <map>
#include <cmath>
#define ll long long
using namespace std;

int main()
{
    int k, a,b;
    cin >> k >> a >> b;
    int result =0 ;
    for(int i=1; i<=b; i++){
        if(i*k>=a && i*k<=b){
            result =1 ;
            break;
        }
    }
    if(result==1){
        cout << "OK";
    }
    else{
        cout << "NG";
    }
    return 0;
}
