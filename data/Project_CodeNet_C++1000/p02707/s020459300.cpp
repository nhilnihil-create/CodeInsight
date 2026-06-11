#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> m;
    for(int i = 0; i < n-1; i++){
        int boss;
        cin >> boss;
        m[boss]++;
    }
    for(int i = 1; i <=n; ++i){
        cout << m[i] << endl;
    }

}