#include <iostream>
#include <string>

using namespace std;

int main(){
    int N, cnt = 0;
    string S;

    cin >> N >> S;

    for(int i = 0; i < N - 2; i ++){
        if(S.substr(i, 3) == "ABC")cnt ++;
    }

    cout << cnt << endl;

    return 0;
}