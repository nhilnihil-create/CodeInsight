#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
using ll = long long;

int main (){
    int A,ans = 0;
    for (int i = 0; i < 3; i++){
        cin >> A;
        ans += A;
    }
    if (ans >= 22){cout << "bust" << endl; 
    }else cout << "win" << endl;
    return 0;
}
    

    
