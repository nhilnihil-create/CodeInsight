#include <iostream>
#include <vector>
using namespace std;

int main(void){
    int n,k,q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for(int i = 0;i < q;i++){
        int x;
        cin >> x;
        x--;
        a[x]++;
    }
    for(int i = 0;i < n;i++){
        if(k - q + a[i] > 0){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
