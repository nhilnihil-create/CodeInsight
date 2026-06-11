#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &vec) {
    int len = (int) vec.size();

    for (int i = 0; i < len - 1; ++i) 
        printf("%d ", vec[i]);
    printf("%d\n", vec[len - 1]);


    int i = 1;
    while( i < len ) {
        int j = i - 1, elem = vec[i];
        while ( j >= 0 && vec[j] > elem ) {
            vec[j + 1] = vec[j];
            j--;
        }

        vec[j + 1] = elem;

        for (int i = 0; i < len - 1; ++i) 
            printf("%d ", vec[i]);
        printf("%d\n", vec[len - 1]);
        ++i;
    }
}


int main() {
    int n;
    scanf("%d", &n);
    vector<int> res(n);
    for (auto &el: res) scanf("%d", &el);
    insertion_sort(res);
    return 0;
}

