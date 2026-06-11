#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void output(vector<int> A)
{
    for(int i = 0; i < A.size(); ++i){
        if(i) cout << " ";
        cout << A[i];
    }
    cout << endl;
}
int count;
vector<int> insertionSort(vector<int>& A, int g)
{
    for(int i = g; i < A.size(); ++i){
        // output(A);
        int v = A[i];
        int j = i - g;
        while(j >= 0 && A[j] > v){
            A[j+g] = A[j];
            j -= g;
            ::count++;
        }
        A[j+g] = v;
    }
    // output(A);
    return A;
}
vector<int> GetG(int n)
{
    int h = 1;
    vector<int> G;
    while(h <= n){
        G.push_back(h);
        h = 3 * h + 1;
    }
    reverse(G.begin(), G.end());
    return G;
}
vector<int> shellSort(vector<int>& A)
{
    vector<int> G = GetG(A.size());
    for(int i = 0; i < G.size(); i++){
        insertionSort(A, G[i]);
    }
    return G;
}
int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }
    vector<int> G = shellSort(A);
    cout << G.size() << endl;
    output(G);
    cout << ::count << endl;
    for(int i = 0; i < A.size(); ++i){
        cout << A[i] << endl;;
    }
    
    
    return 0;
}