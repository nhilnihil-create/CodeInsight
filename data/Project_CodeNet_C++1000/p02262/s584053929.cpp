#include    <iostream>
#include    <vector>

using namespace std;

void shellSort(vector<int>& A);
void insertionSort(vector<int>& A, const int g, int& cnt);

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for(int i = 0; i < n; i++)
        cin >> A[i];
    
    shellSort(A);


    return 0;
}


void shellSort(vector<int>& A) {
    // 間隔の数列
    const vector<int> G = {1, 4, 13, 40, 121, 364, 1093, 3280, 9841, 29524, 88573, 265720, 797161, 2391484};
    int m=0, cnt = 0;

    for(int i = 0; A.size() >= G[i]; i++)
        m = i;
    
    for(int i = m; i >= 0; i--)
        insertionSort(A, G[i], cnt);
    
    cout << m+1 << endl;
    cout << G[m];
    for(int i = m-1; i >= 0; i--)
        cout << ' ' << G[i];
    cout << endl;
    
    cout << cnt << endl;
    for(auto a : A)
        cout << a << endl;
}

void insertionSort(vector<int>& A, const int g, int& cnt) {
    for(int i = g; i < A.size(); i++) {
        int v = A[i], j = i - g;
        while(j >= 0 && A[j] > v) {
            A[j+g] = A[j];
            j -= g;
            cnt++;
        }
        A[j+g] = v;
    }
}
