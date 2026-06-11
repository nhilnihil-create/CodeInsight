#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> l(n);
    for(int i = 0; i < n; i++){
        cin >> l[i];
    }

    int dist = 0;
    int num = 0;
    for(num = 0; num < n; num++){
        dist += l[num];
        if(dist > x) break;
    }
    cout << num+1 << endl;
}