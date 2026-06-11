#include <iostream>
#include <vector>
using namespace std;

int main() {
    int i, j, k, N = 0;
    vector<vector<int> > vec;
    int arr[2];

    do {
        cin >> arr[0] >> arr[1];
        vec.push_back(vector<int>(arr, (arr+sizeof(int))));
        ++N;
    } while(arr[0] != 0 && arr[1] != 0);

    for(i=0; i<(N-1); ++i) {
        for(j=0; j<vec[i][0]; ++j) {
            for(k=0; k<vec[i][1]; ++k) {
                cout << '#';
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}