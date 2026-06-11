#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n;
    cin >> n;

    long long a[n];

    for(long long i = 0; i < n; i++){
        cin >> a[i];
    }

    long long count = 1;
    long long broken = 0;

    for(long long i = 0; i < n; i++){
        if(a[i] != count){
            broken++;
        }
        else{
            count++;
        }
    }
    if(count == 1){
        broken = -1;
    }
    cout << broken << endl;
    return 0;
}