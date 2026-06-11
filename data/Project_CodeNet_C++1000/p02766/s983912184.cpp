#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    cout << ((N<K)?1:ceil(log(N)/log(K))) << endl;
}
