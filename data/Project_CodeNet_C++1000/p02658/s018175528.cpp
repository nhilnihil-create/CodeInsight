#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<unsigned long long> v;
    v.reserve(n);
    for(int i = 0; i < n; i++){
        unsigned long long x;
        cin >> x;
        if(x == 0){
            cout << 0 << endl;
            return 0;
        }
        v.push_back(x);
    }
    unsigned long long prod = 1;
    for(int i = 0; i < n; i++){
        if(v[i] <= 1000000000000000000 / prod){
            prod *= v[i];
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << prod << endl;
}
