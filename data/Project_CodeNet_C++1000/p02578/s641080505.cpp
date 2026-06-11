#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int N,s;cin >> N;
    long long r = 0;
    int max;
    cin >> max;
    

    for (int i = 0;i < N-1;i++){
        cin >> s;
        if (max < s){
            max = s;
        }
        else{
            r += max-s;
        }
    }

    cout << r << endl;
}