#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
    int a[200000];
    
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> a[i];

    sort(a, a + N);

    int cnt = 0;
    for (int i = 0; i < N - 1; i++)
        if (a[i] == a[i + 1])
            cnt++;

    if (cnt > 0)
        cout << "NO";
    if (cnt == 0)
        cout << "YES";
}