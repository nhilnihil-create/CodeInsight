#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    n--;
    int l;
    for(l = 0; l < n; l++) if((n >> l) == 0) break;
    n++;
    int a[502][502];
    for(int k = 1; k <= l; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i % (1 << k)) / (1 << (k - 1)) != (j % (1 << k)) / (1 << (k - 1))) a[i][j] = k;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++) cout << a[i][j] << " ";
        cout << endl;
    }
}