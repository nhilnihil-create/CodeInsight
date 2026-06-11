#include <iostream>
using namespace std;

int main(){
    long long n;cin>>n;
    long long acc = 0;
    for (long long i=1;i<=n;i++){
        if (i % 3 == 0 || i % 5 == 0){
            continue;
        } else {
            acc += i;
        }
    }
    cout << acc << endl;
    return 0;
}
