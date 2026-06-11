#include<iostream>
#include<vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    int buka[n + 1];
    for(int i = 0; i < n + 1; i++){
        buka[i] = 0;
    }
    for(int i = 2; i < n + 1; i++){
        int a;
        cin >> a;
        buka[a] += 1;
    }

    for(int i = 1; i <= n; i++){
        cout << buka[i] << endl;
    }
    return 0;
}