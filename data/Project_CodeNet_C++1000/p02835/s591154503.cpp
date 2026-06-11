#include <iostream>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(int i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(int i = 0; i <=(ll)(n); i++)

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a+b+c >= 22){
        cout << "bust" << endl;
    }else{
        cout << "win" << endl;
    }

    return 0;
}