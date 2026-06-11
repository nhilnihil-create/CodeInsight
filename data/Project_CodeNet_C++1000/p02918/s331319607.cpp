#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    string s;
    cin >> s;
    int segment = 1;
    for(int i =0; i < N - 1; i++){
        if(s.at(i) != s.at(i + 1)) segment ++;
    }
    // cout << segment << endl;
    int temp = segment/2;
    segment = max(1, segment - 2*K);
    cout << N - segment << endl;
}