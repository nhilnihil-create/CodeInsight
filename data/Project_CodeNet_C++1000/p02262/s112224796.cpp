#include <iostream>
#include <vector>
using namespace std;

void shellSort(int x[], int N);
void insertionSort(int x[], int N, int g);
void trace(int x[], int N);

long long gCount = 0;

int main(){
    int N;

    cin >> N;

    int x[N];

    for(int i = 0; i < N; i++){
        cin >> x[i];
    }
    shellSort(x, N);
    cout << gCount << endl;
    trace(x, N);

    return 0;
}

void shellSort(int x[], int N){
    int num = 0, i, h =1;
    vector<int> g;

    i = 0;
    do{
        g.push_back(h);
        h = h * 3 + 1;
        i++;
    }while(h < N);
    cout << g.size() << endl;
    for(i = g.size() - 1 ; i >= 0; i--){
        cout << g[i] << " ";
        insertionSort(x, N, g[i]);
    }
    cout << endl;
}

void insertionSort(int x[], int N, int g){
    int tmp, i, j;

    for(i = g; i < N; i++){
        tmp = x[i];
        j = i - g;
        while(j >= 0 && x[j] > tmp){
            x[j + g] = x[j];
            j = j - g;
            gCount++;
        }
        x[j + g] = tmp;
    }
    // trace(x, N);
}

void trace(int x[], int N){
    for(int i = 0; i < N; i++){
        cout << x[i] << endl;
    }
}