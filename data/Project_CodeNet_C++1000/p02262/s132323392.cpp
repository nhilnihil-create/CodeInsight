#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void WriteLine_Container(const T& container);
void InsertionSort(vector<int>& v, int n, int g, int& cnt);
void ShellSort(vector<int>& v, int n);

int main() {
    int len;
    cin >> len;
    vector<int> A(len);
    for (int i = 0; i < len; i++) cin >> A[i];

    ShellSort(A, A.size());

    for_each(A.begin(), A.end(), [](int x) {
        cout << x << endl;
    });

    return 0;
}



template <typename T>
void WriteLine_Container(T& container) {

    auto it = container.begin();
    while (true) {
        cout << *it;
        it++;
        if (it == container.end()) break;
        else cout << " ";
    }
    cout << endl;
}


void InsertionSort(vector<int>& v, int n, int g, int& cnt) {
    for (int i = g; i < n; i++) {
        int temp = v[i];
        int j = i - g;
        while (j >= 0 && v[j] > temp) {
            v[j + g] = v[j];
            j = j - g;
            cnt++;
        }
        v[j + g] = temp;
    }
}


void ShellSort(vector<int>& v, int n) {
    int cnt = 0;

    list<int> li;
    li.push_front(1);
    
    for (int i = 4; i < v.size(); i = i * 3 + 1) {
        li.push_front(i);
    }
    int m = li.size();

    cout << m << endl;
    
    WriteLine_Container(li);
    
    for_each(li.begin(), li.end(), [&](int x) {
        InsertionSort(v, n, x, cnt);
    });

    
    cout << cnt << endl;
}