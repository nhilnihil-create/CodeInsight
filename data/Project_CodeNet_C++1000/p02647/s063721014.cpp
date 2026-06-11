#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> A;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        A.push_back(a);
    }
    vector<int> B;
    for(int i = 0; i < k; i++){
        B.assign(n+1, 0);
        for(int j = 0; j < n; j++){
            int d = A[j];
            B[max(0, j-d)]++;
            B[min(n, d+j+1)]--;
        }
        for(int j = 1; j < n; j++)B[j] += B[j-1];
        B.pop_back();
        if (A == B) break;
        swap(A, B);
    }

    for(auto a : A)cout << a << " ";
    cout << endl;
    return 0;
}