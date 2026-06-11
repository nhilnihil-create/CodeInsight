#include <iostream>
#include <vector>
using namespace std;

long long cnt;
int A[1000000];
vector<int> G;
void insertionSort (int A[], int n, int g){
    for (int i = g; i < n; ++i){
        for (int j = i; j >= g; j -= g){
            // 如果有序就直接跳过，因为前面的都已经有序，不需要再做比较。
            if (A[j-g] <= A[j])
                break;
            else{
                swap(A[j-g], A[j]);
                cnt++;
            }
        }
        /*int v = A[i];
        int j = i - g;
        while (j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j = j - g;
            cnt++;
        }
        A[j+g] = v;*/
    }
}
void shellSort (int A[], int n){
    int h = 1;
    while (h <= n){
        G.push_back(h);
        h = 3 * h + 1;
    }
    for (int i = G.size()-1; i >= 0; --i){
        insertionSort(A, n, G[i]);
    }
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> A[i];
    }
    shellSort(A, n);
    cout << G.size() << endl;
    for (int i = G.size()-1; i >= 0; --i){
        if (i == G.size()-1)
            cout << G[i];
        else
            cout << " " << G[i];
    }
    cout << endl;
    cout << cnt << endl;
    for (int i = 0; i < n; ++i){
        cout << A[i] << endl;
    }
    return 0;
}

