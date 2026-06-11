#include <iostream>
#include <vector>

using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> q;
    for(int i=1; i<=n; i++) {
        if(n%i==0) q.push_back(i);
    }
    int size = q.size();
    if(size%2){
        if (q[size/2]<=9) {
            cout << "Yes" << endl;
            return 0;
        }
    } else {
        if (q[size/2]<=9 && q[size/2-1]<=9) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}