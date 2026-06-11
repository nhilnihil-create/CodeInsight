#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void SelectSort(int x[], int N);
void BubbleSort(int x[], int N);
void InsertSort(int x[], int N, int num);
void ShellSort(int x[], int N);
void Trace(int x[], int N);
void Trace2(int x[], int N);

int gCount = 0;

int main() {
    int N;

    cin >> N;

    int x[N];

    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }
    //SelectSort(x, N);
    //BubbleSort(x, N);
    ShellSort(x, N);
    Trace2(x, N);
    //cout << gCount << endl;

    return 0;
}


void SelectSort(int x[], int N) {
    int min;

    for (int i = 0; i < N - 1; i++) {
        min = i;
        for (int j = i; j < N; j++) {
            if (x[min] > x[j]) {
                min = j;
            }
        }
        if (i != min) {
            gCount++;
            swap(x[min], x[i]);
        }
    }
}

void BubbleSort(int x[], int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = N - 1; j > i; j--) {
            if (x[j - 1] > x[j]) {
                swap(x[j - 1], x[j]);
                gCount++;
            }
        }
        //Trace(x, N);
    }
}

void ShellSort(int x[], int N) {
     vector<int> g;

     int s = 1, i;
     do {
         g.push_back(s);
         s = s * 3 + 1;
     } while(s < N);
     cout << g.size() << endl;
     for(i = g.size() - 1; i > 0; i--) {
         cout << g[i] << " ";
     }
     cout << g[i] << endl;
     for(i = g.size() - 1; i >= 0; i--) {
         InsertSort(x, N, g[i]);
     }
     cout << gCount << endl;
}

void InsertSort(int x[], int N, int num) {
    for (int i = num; i < N; i++) {
        int v = x[i];
        int j = i - num;
        while (j >= 0 && x[j] > v) {
            x[j + num] = x[j];
            j = j - num;
            gCount++;
        }
        // cout << j + num << endl;
        x[j + num] = v;
        // cout << i << endl;
    }
}

void Trace (int x[], int N) {
    int i;
    for (i = 0; i < N - 1; i++) {
        cout << x[i] << " ";
    }
    cout << x[i] << endl;
}

void Trace2 (int x[], int N) {
    int i;
    for (i = 0; i < N; i++) {
        cout << x[i] << endl;
    }
}