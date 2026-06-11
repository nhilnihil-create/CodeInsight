#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string title[N];
    int sec[N];
    string asleepTitle;
    int asleepFlag = 0;
    int sum = 0;

    for (int i=0;i<N;i++){
        cin >> title[i] >> sec[i];
    }
    cin >> asleepTitle;
    for (int i=0;i<N;i++){
        if (asleepFlag == 1) {
            sum += sec[i];
        }
        if (title[i] == asleepTitle){
            asleepFlag = 1;
        }
    }

    cout << sum << "\n";
}