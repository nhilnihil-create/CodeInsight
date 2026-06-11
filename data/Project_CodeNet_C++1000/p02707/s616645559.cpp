#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int N;
    int sub[200000] = {0};

    cin >> N;
    for(int i = 2; i <= N; i++){
        int a;
        cin >> a;
        sub[a-1]++;
    }
    for(int i = 0; i < N; i++){
        cout << sub[i] << endl;
    }
        return 0;
}
