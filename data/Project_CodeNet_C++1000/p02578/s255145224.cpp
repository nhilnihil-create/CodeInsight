#include <iostream>

using namespace std;

int main() {
    int n, i,  max = 0, temp;
    long long totalHeight = 0;
    int *a;
    cin >> n;
    a = new int[n];
    for (i = 0; i < n; i++){
        cin >> temp;
        *(a + i) = temp;
        if (*(a + i) > max)
            max = *(a + i);
        else if (*(a + i) < max) {
            totalHeight+=(max - *(a + i));            
        }
    }
    cout << totalHeight;
}