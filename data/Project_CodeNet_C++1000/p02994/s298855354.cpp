#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N,L; cin >> N >> L;
    int temp;
    int ind, minim = 1000;
    for(int i = 1; i < N+1; ++i) {
        temp = L+i-1;
        if(abs(temp) < minim) {
            minim = abs(temp);
            ind = i;
        }
    }
    int sumi = 0;
    for(int i = 1; i < N+1; ++i) {
        if(i != ind) {
            sumi += L+i-1;
        }
    }
    cout << sumi;

}