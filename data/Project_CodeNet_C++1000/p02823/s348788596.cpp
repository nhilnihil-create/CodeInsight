#include <iostream>
#include <map>

using namespace std;
int main(){
    long long n,a,b;
    cin >> n >> a >> b;
    if((b-a)%2==0){
        cout << abs(a-b)/2 << endl;
        return 0;
    }
    long long t1 = b;
    long long t2 = n-a;
    if(t1<=t2){
        cout << (a+b-1)/2 << endl;
    }
    else cout << n-(b+a-1)/2 << endl;
    return 0;
}

