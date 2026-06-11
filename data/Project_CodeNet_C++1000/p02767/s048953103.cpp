#define _GLIBCXX_DEBUG
#define MIN 1000000
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main(void){
    int n;
    cin >> n;
    vi X(n);
    for(int &x : X) cin >> x;
    int min = MIN;
    for(int i=1; i<=100; i++){
        int hp = 0;
        for(int &x : X) hp += (x-i)*(x-i);
        if(hp < min) min = hp;
    }
    cout << min << '\n';
    return 0;
}